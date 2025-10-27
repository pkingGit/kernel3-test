cmd_drivers/staging/android/modules.order := {  :; } | awk '!x[$$0]++' - > drivers/staging/android/modules.order
