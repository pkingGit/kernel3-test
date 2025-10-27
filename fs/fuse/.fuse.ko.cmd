cmd_fs/fuse/fuse.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o fs/fuse/fuse.ko fs/fuse/fuse.o fs/fuse/fuse.mod.o;  true
