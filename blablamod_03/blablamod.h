#define MEMORY_SIZE 10
#define DEVICE_NAME "blabladev"
#define DEVICE_CLASS_NAME "blablaclass"

static int __init blablamod_init(void);
static void __exit blablamod_exit(void);

/* Declaration of memory.c functions */
static int memory_open(struct inode *, struct file *);
static int memory_release(struct inode *, struct file *);
static ssize_t memory_read(struct file *, char *, size_t, loff_t *);
static ssize_t memory_write(struct file *, const char *, size_t, loff_t *);

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Dmitrey Salnikov <mr.dimas@meta.ua>"); 
