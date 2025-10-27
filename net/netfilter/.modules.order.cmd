cmd_net/netfilter/modules.order := {   echo net/netfilter/x_tables.ko;   echo net/netfilter/xt_tcpudp.ko; :; } | awk '!x[$$0]++' - > net/netfilter/modules.order
