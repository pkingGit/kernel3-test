cmd_fs/autofs/autofs4.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o fs/autofs/autofs4.ko fs/autofs/autofs4.o fs/autofs/autofs4.mod.o;  true
