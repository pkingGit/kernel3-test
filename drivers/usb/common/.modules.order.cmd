cmd_drivers/usb/common/modules.order := {   echo drivers/usb/common/usb-common.ko; :; } | awk '!x[$$0]++' - > drivers/usb/common/modules.order
