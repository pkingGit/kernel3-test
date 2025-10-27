cmd_security/bpf/modules.order := {  :; } | awk '!x[$$0]++' - > security/bpf/modules.order
