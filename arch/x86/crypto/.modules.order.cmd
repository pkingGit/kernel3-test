cmd_arch/x86/crypto/modules.order := {   echo arch/x86/crypto/crc32c-intel.ko; :; } | awk '!x[$$0]++' - > arch/x86/crypto/modules.order
