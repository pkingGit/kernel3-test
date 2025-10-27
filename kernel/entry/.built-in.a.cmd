cmd_kernel/entry/built-in.a := echo >/dev/null; rm -f kernel/entry/built-in.a; ar cDPrST kernel/entry/built-in.a kernel/entry/common.o kernel/entry/syscall_user_dispatch.o
