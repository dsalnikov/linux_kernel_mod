In order to build type:

	make

In order to install module:

	sudo insmod blablamod.ko
	
Check dmesg for output:

	dmesg
	
At the end of output:

	[ 2776.539112] I was assigned major number 247. To talk to
	[ 2776.539115] the driver, create a dev file with
	[ 2776.539119] 'mknod /dev/chardev c 247 0'.
	[ 2776.539122] Try various minor numbers. Try to cat and echo to
	[ 2776.539125] the device file.
	[ 2776.539128] Remove the device file and module when done.
	
Create node for this dev

	sudo mknod /dev/chardev c 247 0
	sudo chmod 777 /dev/chardev

Try to read file by typing:
	
	cat /dev/chardev
	
Sample output:

	I already told you 0 times Hello world!
	I already told you 1 times Hello world!
	I already told you 2 times Hello world!
	
Try to write:

	echo "hello" > /dev/chardev
	
See the diferense in dmesg:

	[ 2872.839241] Sorry, this operation isn't supported.



