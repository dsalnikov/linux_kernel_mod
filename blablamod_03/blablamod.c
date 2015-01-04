#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h> 	/* printk() */
#include <linux/slab.h> 	/* kmalloc() */
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/types.h> 	/* size_t */
#include <asm/uaccess.h> 	/* copy_from/to_user */


#include "blablamod.h" 

/* Global variables of the driver */
/* Major number */
int major;
/* Buffer to store data */
char *buffer;
int buffer_size;
struct class *memory_class;

static struct file_operations fops = {
	.read = memory_read,
	.write = memory_write,
	.open = memory_open,
	.release = memory_release
};

static int __init blablamod_init( void ) { 
	struct device *err_dev;

	printk(KERN_NOTICE "BlablaModule loaded!\n" ); 

	major = register_chrdev(0, DEVICE_NAME, &fops);

	if (major < 0) {
	  printk(KERN_ALERT "Registering char device failed with %d\n", major);
	  return major;
	}

	/* Allocating memory for the buffer */
	buffer = kmalloc(MEMORY_SIZE, GFP_KERNEL); 
	if (!buffer) { 
		blablamod_exit();
		return -ENOMEM;
	} 
	memset(buffer, 0, 1);

	memory_class = class_create(THIS_MODULE, DEVICE_CLASS_NAME);
	err_dev = device_create(memory_class, NULL, MKDEV(major,0),NULL, DEVICE_CLASS_NAME "_" DEVICE_NAME);
	printk(KERN_INFO "Inserting blablamod module, Major: %d\n",major); 
   
	return 0; 
}

static void __exit blablamod_exit( void ) { 
	unregister_chrdev(major, DEVICE_NAME);
	
	/* Freeing buffer memory */
	if (buffer) {
		kfree(buffer);
	}

	device_destroy(memory_class,MKDEV(major,0));
	class_unregister(memory_class);
	class_destroy(memory_class);

	printk(KERN_NOTICE "BlablaModule unloaded!\n" ); 
}

module_init( blablamod_init ); 
module_exit( blablamod_exit );


static int memory_open(struct inode *inode, struct file *filp) {

  /* Success */
  return 0;
}

static int memory_release(struct inode *inode, struct file *filp) {
 
  /* Success */
  return 0;
}

static ssize_t memory_read(struct file *filp, char *buf, 
                    size_t count, loff_t *f_pos) { 

  size_t c;
  c = count>buffer_size ? buffer_size: count;
  if (*f_pos>0) return 0;
  /* Transfering data to user space */ 
  if (copy_to_user(buf,buffer,c))
  {
	  printk(KERN_WARNING "Error while copy to user!\n");
	  return 0;
  }

  printk("Memory read: %zu \n",c);
  /* Changing reading position as best suits */ 
  if (c >= 0) { 
    *f_pos+=c; 
    return c; 
  } else { 
    return 0;
  }
}
static ssize_t memory_write( struct file *filp, const char *buf,
                      size_t count, loff_t *f_pos) {
  size_t c;
  c = count>MEMORY_SIZE ? MEMORY_SIZE: count;
  printk(KERN_INFO "Memory wrire %zu\n",c); 
  if(copy_from_user(buffer,buf,c))
  {
  	  printk(KERN_WARNING "Error while copy from user!\n");
  }
  buffer_size=c;
  return count;
}

