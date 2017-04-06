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
MODULE_DESCRIPTION("lookaside_cache allocation and deallocation");
MODULE_AUTHOR("RB");

struct test_struct
{
    int test[1024];
};

/** Constants **/
#define NUM_TESTS 10
#define __LINUX_FDTABLE_H
#define FIRST_MINOR 10
#define NR_DEVS 1	//Number of device numbers

//Function Declarations for syscall definitions
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl(struct file *, unsigned int, unsigned long);

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
char *devname = "myChar";	//contains device name
int majNo;
static dev_t mydev;	//encodses major number and minor number
struct cdev *my_cdev;	//holds character device driver discriptor

//class and device structure
static struct class *mychar_class;
static struct device *mychar_device;

// myOpen: open function of the pseudo driver

int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "Open successful\n");
	return 0;
}

// myRelease: close function of the pseudo driver

int myRelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File releaseed \n");
	return 0;
}


// myInit: init function of the kernel module

static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

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

// myExit: cleanup function of the kernel module

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

long myIoctl(struct file *fp, unsigned int pid, unsigned long num)
{
	struct kmem_cache *cache;
	struct test_struct **structs;
	int i;
	int j = 0;
	int k;

	structs = (struct test_struct **) kmalloc (sizeof (struct test_struct *) * NUM_TESTS, GFP_KERNEL);

	if (structs == NULL){
		printk(KERN_ERR "%s: Unable to allocate memory\n", __func__);
		return 0;
	}

	printk(KERN_ERR "Creating\n");
	cache = KMEM_CACHE(test_struct, 0);

	if (cache == NULL){
		printk(KERN_ERR "ERROR: %s: Failed to allocate lookaside cache \n", __func__);
		kfree(structs);
		return 0;
	}

	printk(KERN_ERR "Allocating\n");

	for (i= 0; i < NUM_TESTS; i++){
		structs[i]= kmem_cache_alloc(cache, GFP_KERNEL);
		for (j = 0; j < 1024; j++)
			(*structs + i) -> test[j] = j;
		if (structs[i] == NULL)
			printk(KERN_ERR "ERROR: Failed to allocate\n");
	}

	for (i = 0; i < NUM_TESTS; i++){
		for (j = 0; j < 1024; j++) {
			k = ((*structs + i)-> test[j]);
//			printk (KERN_INFO "%d " k);
			printk (KERN_INFO " %d ", k);
		}
	}

	printk(KERN_ERR "Freeing\n");
	for (i = 0; i < NUM_TESTS; i++){
		if (structs[i])
			kmem_cache_free(cache, structs[i]);
	}

	printk(KERN_ERR "Shrinking\n");
	kmem_cache_shrink(cache);

	printk(KERN_ERR "Destroying\n");
	kmem_cache_destroy(cache);

	kfree(structs);

	return 0;
}
