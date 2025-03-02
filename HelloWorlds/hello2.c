/**
 * @file hello2.c
 * @brief Showing how to make custom init/cleanup files.
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>

static int __init hello_2_init(void) 
{
    // Expands into prink(KERN_INFO "Hello world 2!!\n");
    pr_info("Hello world 2!!\n");
    return 0;
}

static void __exit hello_2_exit(void)
{
	pr_info("Goodbye world 2!!\n");
}

// Specify custom names for init and cleanup
module_init(hello_2_init);
module_exit(hello_2_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Josh L Borthick");