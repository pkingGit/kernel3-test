cmd_drivers/leds/blink/modules.order := {  :; } | awk '!x[$$0]++' - > drivers/leds/blink/modules.order
