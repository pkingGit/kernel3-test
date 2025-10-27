cmd_drivers/usb/core/modules.order := {   echo drivers/usb/core/usbcore.ko; :; } | awk '!x[$$0]++' - > drivers/usb/core/modules.order
