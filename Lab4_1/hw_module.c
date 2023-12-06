#include <linux/kernel.h>
#include <linux/module.h>

MODULE_AUTHOR("Denys Shliakhtun"); 
MODULE_DESCRIPTION("Lab1 test kernel module"); 
MODULE_LICENSE("MIT"); 

static int __init hw_init(void)
{
    printk(KERN_ERR "Input, Kernel!\n");
    return 0;
}

static void __exit hw_exit(void)
{
    printk(KERN_ERR "It out from, Kernel!\n");
}

module_init(hw_init);
module_exit(hw_exit);