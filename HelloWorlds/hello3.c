/**
 * @file hello.c
 * @brief Showing how to use macros __init, __exit, __initdata for
 *        making the init function automatically clean its memory
 *        with built-in drivers, making the exit function ignored
 *        with built-in drivers, and denoting global data which
 *        goes along with the module, respectively.
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

static int hello3_data __initdata = 3;

static int __init hello_3_init(void) 
{
    pr_info("Hello, world! + %d\n", hello3_data);
    return 0;
}

static void __exit hello_3_exit(void) {
    pr_info("Goodbye, world!\n");
}

module_init(hello_3_init);
module_exit(hello_3_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Josh Borthick");