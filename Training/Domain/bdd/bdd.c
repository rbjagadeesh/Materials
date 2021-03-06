#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/vmalloc.h>
#include <linux/genhd.h>
#include <linux/blkdev.h>
#include <linux/hdreg.h>

MODULE_LICENSE("Dual BSD/GPL");

//Initialization routines
static int myInit(void);
static void myExit(void);

/*global variables*/
char *modulename = "myBlock";	//contains device name
int major = 0;					//major number

//Function Declarations for syscall definitions
//int myOpen(struct inode *inode, struct file *filep);
//int myRelease(struct inode *in, struct file *fp);
//long ioct(struct file *, unsigned int, unsigned long);

static struct block_dev {
    unsigned long size;
//    spinlock_t lock;
    u8 *data;
    struct gendisk *gd;
}*dev = NULL;

static struct block_device_operations blk_ops = {
	.owner = THIS_MODULE
//	.ioctl = ioct
//	.open = myOpen,
//	.release = myRelease,
};
/*
//myopen: open function of the pseudo driver
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
*/
// myInit: init function of the kernel module
static int __init myInit(void)
{
	int ret = -ENODEV;
	static int nsectors = 16;
	static int hardsect_size = 512 * 8;

	printk(KERN_INFO "Initializing block device \n");

	dev = vmalloc(sizeof(struct block_dev));
	memset(dev, 0, sizeof (struct block_dev));
	dev->size = nsectors * hardsect_size;
	dev->data = vmalloc(dev->size);

	if (dev->data == NULL) {
		printk (KERN_NOTICE "vmalloc failure.\n");
		return ret;
	}

	major = register_blkdev(0, modulename);
	if(major < 0) {
		printk(KERN_NOTICE "Device number allocation failed: %d \n", major);
		return ret;
	}

	dev->gd = alloc_disk(1);
	if(! dev->gd) {
		printk(KERN_NOTICE "minor number allocation failed");
		return ret;
	}

	dev->gd->major = major;
	dev->gd->first_minor = 0;
	dev->gd->fops = &blk_ops;
//	dev->gd->queue = dev->queue;
	dev->gd->private_data = dev;
//	snprintf (dev->gd->disk_name, 32, "sbull%c", which + 'a');
	set_capacity(dev->gd, nsectors*(hardsect_size/512));

	add_disk(dev->gd);

	return 0;
}

static void __exit myExit(void)
{
	del_gendisk(dev->gd);
	put_disk(dev->gd);
	unregister_blkdev(major, modulename);
//    blk_cleanup_queue(Queue);
    vfree(dev->data);
}

module_init(myInit);
module_exit(myExit);
/*
long ioct(struct file *fp, unsigned int pid, unsigned long n)
{
	struct task_struct *mytask = current;

    printk( "current pid : %d\n", mytask->pid);
    printk( "major : %d\n", dev->gd->major);
    printk( "Name of module : %s\n",mytask->comm);
	
	return 0;
}*/
