cmd_drivers/staging/modules.order := {   cat drivers/staging/media/modules.order;   cat drivers/staging/android/modules.order; :; } | awk '!x[$$0]++' - > drivers/staging/modules.order
