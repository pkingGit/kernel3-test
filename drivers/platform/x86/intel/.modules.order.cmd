cmd_drivers/platform/x86/intel/modules.order := {   cat drivers/platform/x86/intel/pmc/modules.order; :; } | awk '!x[$$0]++' - > drivers/platform/x86/intel/modules.order
