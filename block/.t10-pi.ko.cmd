cmd_block/t10-pi.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o block/t10-pi.ko block/t10-pi.o block/t10-pi.mod.o;  true
