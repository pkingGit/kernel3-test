cmd_block/modules.order := {   cat block/partitions/modules.order;   echo block/t10-pi.ko; :; } | awk '!x[$$0]++' - > block/modules.order
