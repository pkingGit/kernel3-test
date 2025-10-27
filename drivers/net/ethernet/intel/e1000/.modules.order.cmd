cmd_drivers/net/ethernet/intel/e1000/modules.order := {   echo drivers/net/ethernet/intel/e1000/e1000.ko; :; } | awk '!x[$$0]++' - > drivers/net/ethernet/intel/e1000/modules.order
