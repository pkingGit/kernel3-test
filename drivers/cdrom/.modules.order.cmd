cmd_drivers/cdrom/modules.order := {   echo drivers/cdrom/cdrom.ko; :; } | awk '!x[$$0]++' - > drivers/cdrom/modules.order
