cmd_arch/x86/xen/modules.order := {  :; } | awk '!x[$$0]++' - > arch/x86/xen/modules.order
