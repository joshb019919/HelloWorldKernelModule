/**
 * @file hello.c
 * @brief Introducing command line arguments.
 */
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");

// Globals to be included in the module with module_param
static int i = 5;
static short int si = 1;
static long int li = 1000;
static char *str = "This is great fun!";
static int intarr[6] = {0,1,2,3,4,5};

// Will be given the value of the number of arguments supplied by
// the calling command in the terminal
static int arr_argc = 0;

// module_param(argname, type, permission_bits);
// MODULE_PARM_DESC(argname, arg_description);
// The one makes the kernel recognize the global attribute as a
// supplied command line argument, and the second explains it to future
// devs and users
module_param(i, int, 0);
MODULE_PARM_DESC(i, "An integer for s's and g's");
module_param(si, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(si, "A very short int, indeed");
module_param(li, long, S_IRUSR);
MODULE_PARM_DESC(li, "Such a long long way to li-rary!!");
module_param(str, charp, 0000);
MODULE_PARM_DESC(str, "Fun with Strings!");

// module_param_array(arrname, type, count_ptr, permissions);
// Special function for adding arrays as args
module_param_array(intarr, int, &arr_argc, 0000);
MODULE_PARM_DESC(intarr, "A super array.");

static int __init hello_5_init(void)
{
    pr_info("Hello World 5!!\n");

    // Can be used as normal
    pr_info("i = %d\n", i);
    pr_info("si = %hd\n", si);
    pr_info("li = %ld\n", li);
    pr_info("str = %s\n", str);
    for (int j = 0; j < ARRAY_SIZE(intarr); ++j) {
        pr_info("intarr at %d = %d\n", j, intarr[j]);
    }
    pr_info("# of arr args supplied = %d", arr_argc);
    return 0;
}

static void __exit hello_5_exit(void)
{
    pr_info("Goodbye, worldie!!\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);