/**
 * @file hello.c
 * @brief Specifically to reveal the author and description globals.
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Josh Borthick");
MODULE_DESCRIPTION("A simple test module to learn Linux kernel " \
        "module programming");

static int __init hello_4_init(void)
{
    pr_info("Hello World 4!!\n");
    return 0;
}

static void __exit hello_4_exit(void)
{
    pr_info("Goodbye, worldie!!\n");
}

module_init(hello_4_init);
module_exit(hello_4_exit);
