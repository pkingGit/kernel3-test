cmd_drivers/cdrom/cdrom.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o drivers/cdrom/cdrom.ko drivers/cdrom/cdrom.o drivers/cdrom/cdrom.mod.o;  true
