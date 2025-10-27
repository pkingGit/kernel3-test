cmd_fs/autofs/modules.order := {   echo fs/autofs/autofs4.ko; :; } | awk '!x[$$0]++' - > fs/autofs/modules.order
