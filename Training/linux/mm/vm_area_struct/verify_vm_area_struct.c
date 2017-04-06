/** System Includes **/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/sched.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<linux/fdtable.h>
#include<linux/mount.h>
#include<linux/string.h>

MODULE_LICENSE("Dual BSD/GPL");

/** Constants **/
#define __LINUX_FDTABLE_H
#define FIRST_MINOR 10
#define NR_DEVS 1	//Number of device numbers
//Function Declarations for syscall definitions
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl(struct file *, unsigned int, unsigned long);
void mypath(struct dentry *dn);

//Initialization routines
static int myInit(void);
static void myExit(void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myIoctl
};

/* GLobal variables */
char *devname;	//contains device name
int majNo;
static dev_t mydev;	//encodses major number and minor number
struct cdev *my_cdev;	//holds character device driver discriptor

/* TO accept input from the command line */
module_param(devname, charp, 0000);

//class and device structure
static struct class *mychar_class;
static struct device *mychar_device;

/*
 * myOpen: open function of the pseudo driver
 */

int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "Open successful\n");
	return 0;
}

/*
 * myRelease: close function of the pseudo driver
 */

int myRelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File releaseed \n");
	return 0;
}

/*
 * myInit: init function of the kernel module\
 */

static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

	struct task_struct *get_pid1;
    get_pid1 = current;
    printk( "current pid :%d\n",get_pid1 ->pid);
	
	printk(KERN_INFO "Initializing Character Device \n");

	// Allocation Device Numbers
	status = alloc_chrdev_region( &mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0) {
		printk(KERN_NOTICE "Device number allocation failed: %d \n", status);
		goto err;
	}

	printk(KERN_INFO "Major number allocated = %d \n", MAJOR(mydev));
	my_cdev = cdev_alloc();	//Allocate memory for my_cdev
	if(my_cdev == NULL) {
		printk(KERN_ERR "cdev_alloc failed \n");
		goto err_cdev_alloc;
	}

	cdev_init(my_cdev, &fops);	//Initialize my_cdev with fops
	my_cdev->owner = THIS_MODULE;

	status = cdev_add(my_cdev, mydev, NR_DEVS);	//Add my_cdev to the list
	if(status) {
		printk(KERN_ERR "cdev_add failed \n");
		goto err_cdev_add;
	}

	//Create a class and an entry in sysfs

	mychar_class = class_create(THIS_MODULE, devname);
	if(IS_ERR(mychar_class)) {
		printk(KERN_ERR "class_create() failed \n");
		goto err_class_create;
	}

	//create mychar_device in sysfs and an
	//device entry will be made in /dev directory
mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR "device_create() failed \n");
		goto err_device_create;
	}

	return 0;

err_device_create:
	class_destroy(mychar_class);

err_class_create:
	cdev_del(my_cdev);

err_cdev_add:
	kfree(my_cdev);

err_cdev_alloc:
	unregister_chrdev_region(mydev, NR_DEVS);

err:
	return ret;
}

/*
 * myExit: cleanup function of the kernel module
 */

static void myExit(void)
{
	printk(KERN_INFO "Exiting the Character Driver \n");

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;

}

module_init(myInit);
module_exit(myExit);

long myIoctl(struct file *fp, unsigned int pid, unsigned long n)
{
	struct task_struct *my_task = current;
	struct vm_area_struct *vm = my_task->mm->mmap;
	unsigned long ino;
	unsigned int rdev;
	struct dentry *dn = NULL;

	printk(KERN_INFO "my_pid in module %d\n", my_task->pid);
	printk(KERN_INFO "Executable object name is %s\n\n", my_task->comm);

	while((void *) vm != NULL) {

		printk(KERN_INFO "%p-%p ",(void *) vm -> vm_start, ( void *)vm -> vm_end);

		if((vm -> vm_flags) & 0x00000001) {
			printk("r");
		} else {
			printk("-");
		}

		if((vm -> vm_flags) & 0x00000002) {
			printk("w");
		} else {
			printk("-");
		}

		if((vm -> vm_flags) & 0x00000004) {
			printk("x");
		} else {
			printk("-");
		}

		if((vm -> vm_flags) & 0x00000008) {
			printk("s ");
		} else {
			printk("p ");
		}

		if(vm -> vm_file != NULL) {
			printk("%05lx000 ", (vm -> vm_pgoff));

			rdev = vm -> vm_file -> f_path.mnt -> mnt_sb -> s_dev;
			printk("%02x:%02x ", (rdev >> 20), (rdev & 0x000FFFFF));

			ino = vm -> vm_file -> f_path.dentry -> d_inode -> i_ino;
			printk("%ld ", ino);

			dn = vm -> vm_file -> f_path.dentry;
			mypath(dn);

			printk("\n");
		} else {
			printk("00000000 ");
			printk("00:00 ");
			printk("0 ");
			if(my_task -> mm -> start_brk == vm -> vm_start) {
				printk("[heap]");
			} else if(my_task -> mm -> start_stack == vm -> vm_start) {
				printk("[stack]");
			}
			printk("\n");
		}

		vm = vm -> vm_next;
	}
	return 0;
}
void mypath(struct dentry *dn)
{
	if(strcmp(dn -> d_name.name, "/") != 0) {
		mypath(dn -> d_parent);
		printk("/%s", dn -> d_name.name);
	}
}

EXPORT_SYMBOL_GPL(fops);	
EXPORT_SYMBOL(myIoctl);	
