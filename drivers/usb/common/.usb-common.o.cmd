cmd_drivers/usb/common/usb-common.o := ld -m elf_x86_64 -z noexecstack   -r -o drivers/usb/common/usb-common.o drivers/usb/common/common.o drivers/usb/common/debug.o drivers/usb/common/led.o
