# HelloWorldKernelModule
A Linux kernel module to add "Hello World!" to the journal logs.

USAGE: 
Issue the `make` command from a terminal prompt in the directory containing both files.
Check contents of kernel module with `modinfo hello.ko`.
Add module to kernel with `sudo insmod hello.ko`.
Check that the module is loaded with `lsmod | grep kernel`.
Remove the module from the kernel with `sudo rmmod hello`.
Check the log output with `journalctl --since "5 minutes ago" | grep kernel`.

Kernel space programming is different than user space coding.  Instead of code that compiles with no squiggles, it gets added to the kernel as a module.  Instead of printing to the screen in a console, it prints a log to the Linux journal, which can be viewed with journalctl.

Kernel modules utilize log levels, like KERN_INFO or KERN_WARN, inside of a call to `printk` in the start function.  A single space separates arguments, the second of which is the text to write.
