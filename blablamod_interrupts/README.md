In order to build type:

	make

In order to install module:

	sudo insmod blablamod.ko
	
Check dmesg for output:

	dmesg
	
Remove module from system:

	sudo rmmod blablamod
	
Check interrupts 

	$ cat /proc/interrupts 
		       CPU0       CPU1       CPU2       CPU3       
	  0:         31          0          0          0   IO-APIC-edge      timer
	  1:       9609          0          0          0   IO-APIC-edge      i8042
	  8:          1          0          0          0   IO-APIC-edge      rtc0
	  9:          3          0          0          0   IO-APIC-fasteoi   acpi
	 10:          0          0          0          0   IO-APIC-edge      my_interrupt
	 12:        271          0          0          0   IO-APIC-edge      i8042


