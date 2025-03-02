# Simply add more of these to include more files in the module
# obj-m += hello.o
# obj-m += hello2.o
# obj-m += hello3.o
# obj-m += hello4.o
# obj-m += hello5.o

# Denotes to kernel the overall name of module
obj-m += split_files.o
# Tells kernel which files to combine to make the above
split_files-objs := hello_split.o goodbye_split.o

PWD := $(CURDIR)

# Commands; basically never change
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean