In order to build type:

	make

In order to install module:

	sudo insmod blablamod.ko gpio_pin=21 timer_period=100
	
Check gpio21 for output.
Go to the sysfs folder:

	cd /sys/module/blablamod/

Check parameters:

	$ ls -l parameters/
	total 0
	-rwxr-xr-x 1 root root 4096 Mar  2 19:52 gpio_pin
	-rwxr-xr-x 1 root root 4096 Mar  2 19:52 timer_period
	$ cat parameters/gpio_pin
	21

Try to change parameter:

	# echo 20 > parameters/timer_period
	
Unload:

	sudo rmmod blablamod

