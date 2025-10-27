cmd_security/tomoyo/modules.order := {  :; } | awk '!x[$$0]++' - > security/tomoyo/modules.order
