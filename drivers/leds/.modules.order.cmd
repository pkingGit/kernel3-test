cmd_drivers/leds/modules.order := {   cat drivers/leds/trigger/modules.order;   cat drivers/leds/blink/modules.order; :; } | awk '!x[$$0]++' - > drivers/leds/modules.order
