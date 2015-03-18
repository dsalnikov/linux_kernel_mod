Linux Kernel Thread example

In order to build type:

	make

In order to install module:

	sudo insmod blablamod.ko
	
Check dmesg for output:

	dmesg
	
Output:

    [ 3477.526076] Blablamod: blablamod_init():
    [ 3477.526119] Blablamod: HS: 100.
    [ 3477.530524] Blablamod: thread_function(): data = 85.
    [ 3478.537524] Blablamod: thread_function(): 317821.
    [ 3479.547541] Blablamod: thread_function(): 317922.
    [ 3480.557670] Blablamod: thread_function(): 318023.

Check ps:
    
    $ ps -ef | grep bla
    root      8514     2 98 20:28 ?        00:00:09 [Blablathread]

Remove module from system:

	sudo rmmod blablamod
	
Check dmesg for output:

	[ 3477.526076] Blablamod: blablamod_init():
    [ 3477.526119] Blablamod: HS: 100.
    [ 3477.530524] Blablamod: thread_function(): data = 85.
    [ 3478.537524] Blablamod: thread_function(): 317821.
    [ 3479.547541] Blablamod: thread_function(): 317922.
    [ 3480.557670] Blablamod: thread_function(): 318023.
    ...
    [ 3489.647786] Blablamod: thread_function(): 318932.
    [ 3490.658054] Blablamod: thread_function(): 319033.
    [ 3491.667822] Blablamod: thread_function(): 319134.
    [ 3491.865970] Blablamod unloaded!




