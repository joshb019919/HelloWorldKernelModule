#include <linux/init.h>
#include <linux/module.h>

// No init function!!

static void __exit split_file_cleanup(void)
{
    pr_info("...and finished in another!\n");
}

module_exit(split_file_cleanup);