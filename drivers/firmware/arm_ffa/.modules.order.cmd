cmd_drivers/firmware/arm_ffa/modules.order := {  :; } | awk '!x[$$0]++' - > drivers/firmware/arm_ffa/modules.order
