/**
 * @file hello.c
 * @brief Simple explanation of getting kernel modules running.
 */
#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void) {
    printk(KERN_INFO "Hello world!\n");

    // Must be 0, else won't load--acts like a security issue.
    return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world!\n");
}

// License notice required to silence "kernel taint" msg
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Josh L Borthick");