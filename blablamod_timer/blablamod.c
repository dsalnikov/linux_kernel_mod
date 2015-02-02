#include <linux/init.h> 
#include <linux/module.h> 
#include <linux/timer.h>

#include "blablamod.h" 

static struct timer_list my_timer;

void my_timer_callback(unsigned long data)
{
	printk(KERN_NOTICE "my_timer_callback called (%ld): %lu.\n", jiffies, data);
}

static int __init blablamod_init( void ) { 
    int ret;
    
    printk(KERN_NOTICE "BlablaModule loaded!\n"); 
   
	// my_timer, function, data
	setup_timer( &my_timer, my_timer_callback, 10 );

	printk(KERN_NOTICE "Starting timer to fire in 200ms (%ld)\n", jiffies);
	ret = mod_timer(&my_timer, jiffies + msecs_to_jiffies(200));
	if (ret)
		printk(KERN_ALERT "Error in mod_timer\n");

   return 0; 
}

static void __exit blablamod_exit( void ) { 
	int ret = del_timer( &my_timer );
	if (ret)
		printk(KERN_ALERT "The timer is still in use...\n");

   printk(KERN_NOTICE "BlablaModule unloaded!\n" ); 
}

module_init( blablamod_init ); 
module_exit( blablamod_exit );
