In order to build type:

	make

Samle building output:

$ make
make -C /lib/modules/3.17.7-300.fc21.x86_64/build  M=/home/lamazavr/kernel_module/blablamod_01  modules 
make[1]: вход в каталог «/usr/src/kernels/3.17.7-300.fc21.x86_64»
  CC [M]  /home/lamazavr/kernel_module/blablamod_01/blablamod.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/lamazavr/kernel_module/blablamod_01/blablamod.mod.o
  LD [M]  /home/lamazavr/kernel_module/blablamod_01/blablamod.ko
make[1]: выход из каталога «/usr/src/kernels/3.17.7-300.fc21.x86_64»

In order to install module:

	sudo insmod blablamod.ko
	
Check dmesg for output:

	dmesg
	
At the end of output:

	[  544.652030] BlablaModule loaded!
	
Remove module from system:

	sudo rmmod blablamod
	
Check dmesg for output:

	[  640.847625] BlablaModule unloaded!

Check information about module:

	modinfo blablamod.ko
	
For example:

	filename:       /home/lamazavr/kernel_module/blablamod_01/blablamod.ko
	author:         Dmitrey Salnikov <mr.dimas@meta.ua>
	license:        GPL
	depends:        
	vermagic:       3.17.7-300.fc21.x86_64 SMP mod_unload 


