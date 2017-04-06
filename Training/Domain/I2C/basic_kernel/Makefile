obj-m:=kmod.o

KDIR:=/home/jagadeesh/Downloads/domain/gouse/linux
#/home/asish/Desktop/project/pi/linux

PWD:=$(shell pwd)
#CROSS_COMPILE:=/home/asish/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-
CROSS_COMPILE:=/home/jagadeesh/Downloads/domain/gouse/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-
all:
	$(MAKE) -C $(KDIR) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_kmod

