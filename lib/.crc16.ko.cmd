cmd_lib/crc16.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o lib/crc16.ko lib/crc16.o lib/crc16.mod.o;  true
