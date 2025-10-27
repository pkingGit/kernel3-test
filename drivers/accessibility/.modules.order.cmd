cmd_drivers/accessibility/modules.order := {   cat drivers/accessibility/braille/modules.order; :; } | awk '!x[$$0]++' - > drivers/accessibility/modules.order
