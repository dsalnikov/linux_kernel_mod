#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

#include "blablamod.h"

static struct gpio out;
static struct gpio in;
static int irq_num;
static int gpio_val = 0;

static irqreturn_t gpio_isr(int irq, void *data)
{
 //   printk(KERN_INFO "gpio irq: gpio_val=%d\n",gpio_val);
    gpio_set_value(out.gpio,gpio_val);
    gpio_val = (gpio_val) ? 0 : 1; 
    return IRQ_HANDLED;
}

static int __init blablamod_init(void)
{
    int ret;
    out.gpio = 21;
    out.flags = GPIOF_OUT_INIT_LOW;
    out.label = "Output Gpio";

    in.gpio = 17;
    in.flags = GPIOF_IN;
    in.label = "In Gpio";

    ret = gpio_request(out.gpio, out.label);
    if (ret)
    {
        printk(KERN_ALERT "OUT Gpio request failed");
        return -1;
    }
    gpio_direction_output(out.gpio, 0);
    gpio_set_value(out.gpio, 1);

    ret = gpio_request(in.gpio,in.label);
    if (ret)
    {
        printk(KERN_ALERT "In Gpio request failed");
        return -2;
    }

    ret = gpio_to_irq(in.gpio);
    if (ret < 0)
    {
        printk(KERN_ERR "Unable to request IRQ: %d\n", ret);
        return -3;
    }
    irq_num = ret;
    printk(KERN_INFO "Successfully requested IRQ#%d.\n", irq_num);
    ret = request_irq(irq_num,gpio_isr,IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING | IRQF_DISABLED, "gpio_irq", NULL);
    if (ret)
    {
        printk(KERN_ERR "Unable to request irq\n");
        return -4;
    }


    printk(KERN_NOTICE "Blablamod loaded\n");
    return 0;
}

static void __exit blablamod_exit(void)
{
    free_irq(irq_num,NULL);
    gpio_free(in.gpio);
    gpio_free(out.gpio);
    printk(KERN_NOTICE "Blablamod unloaded!\n");
}

module_init(blablamod_init);
module_exit(blablamod_exit);
