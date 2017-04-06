/** System Includes **/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/sched.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<asm/highmem.h>

MODULE_LICENSE("Dual BSD/GPL");

/** Constants **/
#define FIRST_MINOR 10
#define NR_DEVS 1	//Number of device numbers
#define MAX_INDEX 1024
//#define PAGE_OFFSET 0xc0000000

//Function Declarations for syscall definitions
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myioctl(struct file *fp, unsigned int pid, unsigned long);

//Initialization routines
static int myInit(void);
static void myExit(void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myioctl
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

long myioctl(struct file *fp, unsigned int pid, unsigned long num )
{
	int i = 0;
	int k = 0;
	int j = 0;
	unsigned long *va;
	extern struct page *mem_map;
	
	struct task_struct *my_task = current;
	pgd_t *mypgd = my_task -> mm -> pgd;

	printk(KERN_INFO "my_pid in module %d\n", my_task->pid);
	printk(KERN_INFO "comm string is %s\n", my_task->comm);
	
	for(i =0; i < 1024; i++) {
		if(mypgd[i].pgd) {
			for(k = 0; k < 1024; k++) {
				if(mypgd[i].pgd >= 0 && mypgd[i].pgd < 0x38000000) {

					va = (unsigned long *) (((mypgd[i].pgd >> 12) << 12) + 0xc0000000);

					if(va[k]) {
						printk(KERN_INFO "pgd %4d pt %4d PGD %08lx PT %08lx\n",i, k, mypgd[i].pgd, va[k]);
						j++;
					}

				} else {

					va = (unsigned long *)kmap(mem_map + (mypgd[i].pgd >> 12));

					if(va[k]) {
						printk(KERN_INFO "pgd %4d pt %4d PGD %08lx PT %08lx\n",i, k, mypgd[i].pgd, va[k]);
						j++;
					}
				}

			}
		}
	}

	printk (KERN_INFO "total entries %d\n", j);

	return 0;
}
