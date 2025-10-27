cmd_drivers/scsi/sr_mod.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o drivers/scsi/sr_mod.ko drivers/scsi/sr_mod.o drivers/scsi/sr_mod.mod.o;  true
