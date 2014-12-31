
#define DEVICE_NAME "chardev"	/* Dev name as it appears in /proc/devices   */
#define BUF_LEN 80				/* Max length of the message from the device */

static int __init blablamod_init(void);
static void __exit blablamod_exit(void);

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Dmitrey Salnikov <mr.dimas@meta.ua>"); 
