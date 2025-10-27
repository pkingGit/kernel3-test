cmd_crypto/modules.order := {   cat crypto/asymmetric_keys/modules.order;   echo crypto/crct10dif_common.ko;   echo crypto/crct10dif_generic.ko; :; } | awk '!x[$$0]++' - > crypto/modules.order
