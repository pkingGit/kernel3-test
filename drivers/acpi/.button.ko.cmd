cmd_drivers/acpi/button.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o drivers/acpi/button.ko drivers/acpi/button.o drivers/acpi/button.mod.o;  true
