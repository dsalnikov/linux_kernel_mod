#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
 
struct ds1307 {
    u8 sec;
    u8 min;
    u8 hour;
    u8 day;
    u8 date;
    u8 month;
    u8 year;
};
 
static const struct i2c_device_id ds1307_id[] = {
    { "blabla_ds1307", 0 },
    { }
};
MODULE_DEVICE_TABLE(i2c, ds1307_id);
 
 
 
 
static int ds1307_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    int ret;
    const char wr_buf[1] = {0};
    struct ds1307 *buffer = kmalloc(sizeof(struct ds1307), GFP_KERNEL);
 
    printk(KERN_NOTICE "Blablai2c probing!\n" ); 
//try without this
    ret = i2c_master_send(client, wr_buf, 1);
    if (ret < 0)
        return ret;
 
    ret = i2c_master_recv(client, (char *)buffer, sizeof(struct ds1307));
    if (ret < 0)
        return ret;
 
//extern int i2c_master_send(const struct i2c_client *client, const char *buf, int count);
//extern int i2c_master_recv(const struct i2c_client *client, char *buf, int count);
 
    print_hex_dump(KERN_DEBUG, "i2c buffer: ", DUMP_PREFIX_OFFSET, 16, 1, buffer, sizeof(struct ds1307), true);
    return 0;
}
 
static int ds1307_remove(struct i2c_client *client)
{
    printk(KERN_NOTICE "Blablai2c removing!\n" ); 
 
    return 0;
}
 
static struct i2c_driver ds1307_driver = {
    .driver = {
        .name   = "blabla_ds1307",
    },
    .probe          = ds1307_probe,
    .remove         = ds1307_remove,
    .id_table       = ds1307_id,
};
 
// helper macro for i2c device registering
// otherwise use extern int i2c_register_driver(struct module *, struct i2c_driver *) in init 
module_i2c_driver(ds1307_driver);

MODULE_LICENSE("GPL");

