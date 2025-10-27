cmd_sound/pci/snd-intel8x0.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o sound/pci/snd-intel8x0.ko sound/pci/snd-intel8x0.o sound/pci/snd-intel8x0.mod.o;  true
