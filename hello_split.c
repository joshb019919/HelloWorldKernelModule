#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init split_file_init(void)
{
    pr_info("Module started in one file...\n");
    return 0;
}

// No exit function??

module_init(split_file_init);
