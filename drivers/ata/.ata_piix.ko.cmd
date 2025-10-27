cmd_drivers/ata/ata_piix.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o drivers/ata/ata_piix.ko drivers/ata/ata_piix.o drivers/ata/ata_piix.mod.o;  true
