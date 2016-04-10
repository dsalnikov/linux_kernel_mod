In order to build kernel module:

	make

In order to compile DTB:

	dtc -@ -I dts -O dtb -o blablamod-overlay.dtb blablamod-overlay.dts

Or simply install new device:

	# echo blabla_ds1307 0x68 > /sys/class/i2c-adapter/i2c-1/new_device

In order to install:

	sudo make install
	sudo modprobe blablamod

Check dmesg for output:

	dmesg | grep i2c
	
Example output:

[    4.199060] bcm2708_i2c 20804000.i2c: BSC1 Controller at 0x20804000 (irq 79) (baudrate 100000)
[    4.260279] i2c /dev entries driver
[    6.519745] Blablai2c probing!
[    6.534233] i2c buffer: 00000000: 46 29 09 01 10 04 16                             F).....
	
Remove module from system:

	sudo modprobe -r blablamod
