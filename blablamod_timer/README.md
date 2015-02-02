In order to build type:

	make

In order to install module:

	sudo insmod blablamod.ko
	
Check dmesg for output:

	dmesg
	
At the end of output:

	[ 2451.721607] BlablaModule loaded!
	[ 2451.721612] Starting timer to fire in 200ms (4297117690)
	[ 2451.920853] my_timer_callback called (4297117890): 10.

Remove module from system:

	sudo rmmod blablamod
	
Check dmesg for output:

	[ 2459.582765] BlablaModule unloaded!
