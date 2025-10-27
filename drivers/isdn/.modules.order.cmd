cmd_drivers/isdn/modules.order := {   cat drivers/isdn/hardware/modules.order; :; } | awk '!x[$$0]++' - > drivers/isdn/modules.order
