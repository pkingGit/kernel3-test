cmd_drivers/crypto/ccp/modules.order := {  :; } | awk '!x[$$0]++' - > drivers/crypto/ccp/modules.order
