#include <linux/init.h> 
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/timer.h>
#include <linux/gpio.h>

#include "blablamod.h" 

static struct timer_list my_timer; 

static int gpio_pin = 21;
static int gpio_value = 1;
static int timer_period = 1000;
module_param(gpio_pin, int, 0755);
module_param(timer_period, int, 0755);

static struct gpio led;

static void my_timer_callback(unsigned long data)
{
    printk(KERN_NOTICE "timer_callback called (%ld): %lu.\n", jiffies, data);
    gpio_value = (gpio_value) ? 0 : 1;
    gpio_set_value(gpio_pin, gpio_value);
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(timer_period));
}

static int __init blablamod_init( void ) { 
    int ret;
    printk(KERN_NOTICE "Blablatogle module loaded!\n" ); 

    led.gpio = gpio_pin;
    led.flags = GPIOF_OUT_INIT_LOW;
    led.label = "LED";

    if (!gpio_is_valid(gpio_pin))
    {
        printk(KERN_ALERT " GPIO number %d not valid.\n", gpio_pin);
        return 1;
    }
    
    ret = gpio_request(gpio_pin,"LED");
    if (ret)
    {
        printk(KERN_ALERT "Gpio request failed.\n");
        return -2;
    }
    //value 0
    gpio_direction_output(gpio_pin, 0);
    gpio_set_value(gpio_pin, gpio_value);

    setup_timer( &my_timer, my_timer_callback, 10 );
    ret = mod_timer(&my_timer, jiffies + msecs_to_jiffies(timer_period));
    if (ret)
        printk(KERN_ALERT "Error in mod_timer\n");

    return 0; 
}
 
static void __exit blablamod_exit( void ) { 
    int ret;
    printk(KERN_NOTICE "Blablatogle module unloaded!\n" ); 

    if (gpio_is_valid(gpio_pin))
    {
        gpio_direction_output(gpio_pin, 0);
        gpio_set_value(gpio_pin, 0);
    }
    
    gpio_free(led.gpio);
    ret = del_timer( &my_timer );
    if (ret)
        printk(KERN_ALERT "The timer is still in use...\n");
}
 
module_init( blablamod_init ); 
module_exit( blablamod_exit );
