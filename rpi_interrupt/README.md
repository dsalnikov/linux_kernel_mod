In order to build type:

	make

In order to install module:

	sudo insmod blablamod.ko
	
Check dmesg for output:

	dmesg
	
At the end of output:

	[  544.652030] BlablaModule loaded!
	
Remove module from system:

	sudo rmmod blablamod
	
Test interrupt performance.
	
	GPIO17 - input signal 
	GPIO21 - output


