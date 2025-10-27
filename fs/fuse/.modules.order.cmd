cmd_fs/fuse/modules.order := {   echo fs/fuse/fuse.ko; :; } | awk '!x[$$0]++' - > fs/fuse/modules.order
