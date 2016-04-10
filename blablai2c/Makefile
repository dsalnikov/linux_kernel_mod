KDIR = /lib/modules/$(shell uname -r)/build 
PWD = $(shell pwd) 
TARGET = blablamod

obj-m   := $(TARGET).o 

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules 

install:
	cp blablamod.ko /lib/modules/$(shell uname -r)/kernel/drivers/i2c/	

uninstall:
	@rm -f /lib/modules/4.1.21+/kernel/drivers/i2c/$(TARGET).ko

clean: 
	@rm -f *.o .*.cmd .*.flags *.mod.c *.order 
	@rm -f .*.*.cmd *~ *.*~ TODO.*
	@rm -fR .tmp* 
	@rm -rf .tmp_versions 
	
disclean: clean 
	@rm *.ko *.symvers
