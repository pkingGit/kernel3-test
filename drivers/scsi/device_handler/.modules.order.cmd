cmd_drivers/scsi/device_handler/modules.order := {  :; } | awk '!x[$$0]++' - > drivers/scsi/device_handler/modules.order
