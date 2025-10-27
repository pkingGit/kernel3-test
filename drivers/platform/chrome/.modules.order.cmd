cmd_drivers/platform/chrome/modules.order := {  :; } | awk '!x[$$0]++' - > drivers/platform/chrome/modules.order
