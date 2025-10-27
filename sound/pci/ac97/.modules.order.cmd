cmd_sound/pci/ac97/modules.order := {   echo sound/pci/ac97/snd-ac97-codec.ko; :; } | awk '!x[$$0]++' - > sound/pci/ac97/modules.order
