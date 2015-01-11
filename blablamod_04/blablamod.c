#include <linux/init.h> 
#include <linux/module.h> 
#include <linux/moduleparam.h>
#include "blablamod.h" 

static int int_param;
static char *str_param;

/**
 * module_param - typesafe helper for a module/cmdline parameter
 * @value: the variable to alter, and exposed parameter name.
 * @type: the type of the parameter
 * @perm: visibility in sysfs.
 **/
module_param(int_param, int, 0);
module_param(str_param, charp, 0);

static int __init blablamod_init( void ) { 
   printk(KERN_NOTICE "BlablaModule loaded!\n" ); 
   
   printk(KERN_NOTICE "int_param=%i\n", int_param);
   printk(KERN_NOTICE "str_param=%s\n", str_param);
   
   return 0; 
}

static void __exit blablamod_exit( void ) { 
   printk(KERN_NOTICE "BlablaModule unloaded!\n" ); 
}

module_init( blablamod_init ); 
module_exit( blablamod_exit );
