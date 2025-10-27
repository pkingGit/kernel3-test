cmd_lib/crc-t10dif.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o lib/crc-t10dif.ko lib/crc-t10dif.o lib/crc-t10dif.mod.o;  true
