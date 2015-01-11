#include <linux/init.h> 
#include <linux/module.h> 

#include <linux/interrupt.h>

#include "blablamod.h" 

static unsigned long my_irq_dev = 911; //some data
static int my_irq = 10;  // irq line number

static int __init blablamod_init( void ) { 

   if (request_irq(my_irq, my_irq_handler, IRQF_SHARED, "my_interrupt", &my_irq_dev))
   {
       printk(KERN_ERR "rtc: cannot register IRQ %d\n", my_irq);
       return -EIO;
   }

   printk(KERN_NOTICE "BlablaModule loaded!\n" );

   return 0; 
}

static void __exit blablamod_exit( void ) { 

	free_irq(my_irq, &my_irq_dev	);
	printk(KERN_NOTICE "BlablaModule unloaded!\n" );
}

module_init( blablamod_init ); 
module_exit( blablamod_exit );


static irqreturn_t my_irq_handler(int irq, void *dev)
{

	printk(KERN_WARNING "IRQ%d was entered!\n",irq);
	printk(KERN_WARNING "dev=%lu\n", *(unsigned long*)dev);

	return IRQ_HANDLED;
}

