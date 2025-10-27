cmd_fs/configfs/modules.order := {   echo fs/configfs/configfs.ko; :; } | awk '!x[$$0]++' - > fs/configfs/modules.order
