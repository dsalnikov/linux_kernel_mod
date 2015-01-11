In order to build type:

	make

In order to install module:

	sudo insmod blablamod.ko
	
Check dmesg for output:

	$ dmesg
	[ 5273.475539] BlablaModule loaded!
	[ 5273.475546] int_param=0
	[ 5273.475550] str_param=(null)
	
Remove module from system:

	sudo rmmod blablamod
	
Install module with parameters:

	sudo insmod blablamod.ko int_param=100 str_param="blablastring"
	
Check dmesg for output:

	$ dmesg
	[ 5149.029678] BlablaModule loaded!
	[ 5149.029683] int_param=100
	[ 5149.029686] str_param=blablastring

