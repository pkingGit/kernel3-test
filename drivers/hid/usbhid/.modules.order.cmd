cmd_drivers/hid/usbhid/modules.order := {   echo drivers/hid/usbhid/usbhid.ko; :; } | awk '!x[$$0]++' - > drivers/hid/usbhid/modules.order
