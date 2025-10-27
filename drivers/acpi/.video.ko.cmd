cmd_drivers/acpi/video.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o drivers/acpi/video.ko drivers/acpi/video.o drivers/acpi/video.mod.o;  true
