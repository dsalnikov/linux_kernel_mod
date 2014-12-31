#include <linux/init.h> 
#include <linux/module.h> 

#include "blablamod.h" 

static int __init blablamod_init( void ) { 
   printk(KERN_NOTICE "BlablaModule loaded!\n" ); 
   return 0; 
}

static void __exit blablamod_exit( void ) { 
   printk(KERN_NOTICE "BlablaModule unloaded!\n" ); 
}

module_init( blablamod_init ); 
module_exit( blablamod_exit );
