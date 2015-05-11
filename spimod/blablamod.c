#include <linux/init.h> 
#include <linux/module.h> 

#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/sched.h>

static struct task_struct *task;

#include <linux/spi/spi.h>

struct spi_device *spi_dev;

#include "blablamod.h" 

const unsigned char buffer[] = {0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55}; 


int thread_function(void *data)
{
    unsigned long tm = jiffies + msecs_to_jiffies(1000);
    printk(KERN_NOTICE "Blablamod: %s(): data = %d.\n", __func__, (int)data); 
    while(!kthread_should_stop()){
        if (time_after(jiffies, tm))
        {
            tm = jiffies + msecs_to_jiffies(1000);
            printk(KERN_NOTICE "Blablamod: %s(): %lu.\n", __func__, jiffies); 

			spi_write(spi_dev, buffer, sizeof(buffer));	
        }
        schedule();
    }

    return 0;
}





int spi_drv_probe(struct spi_device *spi);
int spi_drv_remove(struct spi_device *spi);

struct spi_driver spi_drv = {
	.driver = {
		.name = "spitest",
		.owner = THIS_MODULE,
	},
	.probe = spi_drv_probe,
	.remove = spi_drv_remove,
};



static int __init blablamod_init( void ) { 
	int ret;	
	printk(KERN_NOTICE "BlablaModule loaded!\n" ); 


	ret = spi_register_driver(&spi_drv);
	if (ret < 0)
	{
		printk(KERN_ALERT "Cant register spi dev.\n");
		return ret;
	}


     
	task = kthread_run(&thread_function,(void *)0xAA,"Blablathread");
	
	return 0; 
}

static void __exit blablamod_exit( void ) { 
	printk(KERN_NOTICE "BlablaModule unloaded!\n" );
	kthread_stop(task); 
	spi_unregister_driver(&spi_drv);
}

module_init( blablamod_init ); 
module_exit( blablamod_exit );

int spi_drv_probe(struct spi_device *spi)
{
	int ret;

	printk(KERN_NOTICE "spi drv probe!\n" );

	spi->bits_per_word = 8;
	spi->mode = SPI_MODE_0;
	spi->max_speed_hz = 500000;
	
	ret = spi_setup(spi);
	if (ret < 0)
		return ret;

	spi_dev = spi;

	spi_write(spi, buffer, sizeof(buffer));	

	return 0;
}

int spi_drv_remove(struct spi_device *spi)
{
	printk(KERN_NOTICE "spi drv remove!\n" );
	return 0;
}


