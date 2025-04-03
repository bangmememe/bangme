CC = gcc
obj-m := exportsymbol_a.o
obj-m += exportsymbol_b.o
obj-m += exportsymbol_c.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean