#include <linux/init.h> 
#include <linux/module.h>

#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/sched.h>

#include "blablamod.h" 

static struct task_struct *task;
static int data = 0x55;

int thread_function(void *data)
{
    unsigned long tm = jiffies + msecs_to_jiffies(1000);
    printk(KERN_NOTICE "Blablamod: %s(): data = %d.\n", __func__, (int)data); 
    while(!kthread_should_stop()){
        if (time_after(jiffies, tm))
        {
            tm = jiffies + msecs_to_jiffies(1000);
            printk(KERN_NOTICE "Blablamod: %s(): %lu.\n", __func__, jiffies); 
        }
        schedule();
    }

    return 0;
}

static int __init blablamod_init( void ) { 
    printk(KERN_NOTICE "Blablamod: %s():\n", __func__); 
    printk(KERN_NOTICE "Blablamod: HS: %d.\n", HZ); 

    task = kthread_run(&thread_function,(void *)data,"Blablathread");
    return 0; 
}
 
static void __exit blablamod_exit( void ) { 
    kthread_stop(task);
    printk(KERN_NOTICE "Blablamod unloaded!\n" ); 
}
 
module_init( blablamod_init ); 
module_exit( blablamod_exit );
