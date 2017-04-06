#include <linux/module.h>
#include <linux/fs.h>
//#include <linux/cdev.h>
//#include <linux/device.h>

#define NO_DEV 		 1
#define FIRST_MINOR  0

int device_number;
char *device_name = "sample_driver";
struct cdev *device_cdev;
struct class *device_class;
static struct device *device_device;
MODULE_LICENSE("Dual BSD/GPL");
#if 0
static int ddriver_init(void)
{

	printk("Driver inserted\n");

	printk("Major number before alloc_chr_region = %d\n", MAJOR(device_number));
	if ((alloc_chrdev_region (&device_number, FIRST_MINOR, NO_DEV, device_name )) < 0) {

		printk("alloc_chrdev_region failed\n");
	}
	
	printk("Major number after alloc_chr_region = %d\n", MAJOR(device_number));
	
#if 0
	device_cdev = cdev_alloc();
	printk("cdev_alloc over\n");
	
	if (device_cdev == NULL) {

		printk("cdev failed\n");
	}

	cdev_init(device_cdev, NULL);
	printk("cdev_init over\n");

	cdev_add(device_cdev, device_number, NO_DEV);
	printk("cdev_add over\n");

	device_class = class_create(THIS_MODULE,device_name );

	if (IS_ERR(device_class)) {                                                 
        printk (KERN_ERR "class_create () failed\n");                           
    }   

	
	device_device = device_create (device_class, NULL, device_number, NULL, device_name);   
                                                                                
    if (IS_ERR (device_device)) {                                               
        printk (KERN_ERR "device_create () failed \n");                         
	}

#endif
	return 0;
}



static void driver_exit( void )
{

	printk("Driver removed\n");
	return;
}

module_init(ddriver_init);
module_exit(driver_exit);

#endif
