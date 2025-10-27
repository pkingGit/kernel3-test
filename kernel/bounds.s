	.file	"bounds.c"
# GNU C89 (Debian 10.2.1-6) version 10.2.1 20210110 (x86_64-linux-gnu)
#	compiled by GNU C version 10.2.1 20210110, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.0, isl version isl-0.23-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -nostdinc -I ./arch/x86/include
# -I ./arch/x86/include/generated -I ./include -I ./arch/x86/include/uapi
# -I ./arch/x86/include/generated/uapi -I ./include/uapi
# -I ./include/generated/uapi -imultiarch x86_64-linux-gnu -D __KERNEL__
# -D CONFIG_X86_X32_ABI -D CC_USING_FENTRY -D KBUILD_MODFILE="./bounds"
# -D KBUILD_BASENAME="bounds" -D KBUILD_MODNAME="bounds"
# -D __KBUILD_MODNAME=kmod_bounds
# -isystem /usr/lib/gcc/x86_64-linux-gnu/10/include
# -include ./include/linux/compiler-version.h
# -include ./include/linux/kconfig.h
# -include ./include/linux/compiler_types.h -MMD kernel/.bounds.s.d
# kernel/bounds.c -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -m64
# -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3
# -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel
# -mindirect-branch=thunk-extern -mindirect-branch-register
# -mfunction-return=thunk-extern -mrecord-mcount -mfentry -march=x86-64
# -auxbase-strip kernel/bounds.s -O2 -Wall -Wundef
# -Werror=strict-prototypes -Wno-trigraphs
# -Werror=implicit-function-declaration -Werror=implicit-int
# -Werror=return-type -Wno-format-security -Wno-sign-compare
# -Wno-frame-address -Wformat-truncation=0 -Wformat-overflow=0
# -Wno-address-of-packed-member -Wframe-larger-than=2048
# -Wimplicit-fallthrough=5 -Wno-main -Wno-unused-but-set-variable
# -Wunused-const-variable=0 -Wdeclaration-after-statement -Wvla
# -Wno-pointer-sign -Wno-stringop-truncation -Wno-zero-length-bounds
# -Wno-array-bounds -Wstringop-overflow=0 -Wno-restrict
# -Wno-maybe-uninitialized -Walloc-size-larger-than=18446744073709551615EiB
# -Werror=date-time -Werror=incompatible-pointer-types
# -Werror=designated-init -Wno-packed-not-aligned -std=gnu90 -p
# -fmacro-prefix-map=./= -fno-strict-aliasing -fno-common -fshort-wchar
# -fno-PIE -fcf-protection=none -falign-jumps=1 -falign-loops=1
# -fno-asynchronous-unwind-tables -fno-jump-tables
# -fno-delete-null-pointer-checks -fno-allow-store-data-races
# -fstack-protector-strong -fno-stack-clash-protection -fno-strict-overflow
# -fstack-check=no -fconserve-stack -fverbose-asm
# options enabled:  -faggressive-loop-optimizations -falign-functions
# -falign-jumps -falign-labels -falign-loops -fallocation-dce
# -fauto-inc-dec -fbranch-count-reg -fcaller-saves -fcode-hoisting
# -fcombine-stack-adjustments -fcompare-elim -fcprop-registers
# -fcrossjumping -fcse-follow-jumps -fdefer-pop -fdevirtualize
# -fdevirtualize-speculatively -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-symbols -feliminate-unused-debug-types
# -fexpensive-optimizations -fforward-propagate -ffp-int-builtin-inexact
# -ffunction-cse -fgcse -fgcse-lm -fgnu-unique -fguess-branch-probability
# -fhoist-adjacent-loads -fident -fif-conversion -fif-conversion2
# -findirect-inlining -finline -finline-atomics -finline-functions
# -finline-functions-called-once -finline-small-functions -fipa-bit-cp
# -fipa-cp -fipa-icf -fipa-icf-functions -fipa-icf-variables -fipa-profile
# -fipa-pure-const -fipa-reference -fipa-reference-addressable -fipa-sra
# -fipa-stack-alignment -fipa-vrp -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots
# -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flra-remat -fmath-errno
# -fmerge-constants -fmerge-debug-strings -fmove-loop-invariants
# -fomit-frame-pointer -foptimize-sibling-calls -foptimize-strlen
# -fpartial-inlining -fpeephole -fpeephole2 -fplt -fprefetch-loop-arrays
# -fprofile -free -freg-struct-return -freorder-blocks
# -freorder-blocks-and-partition -freorder-functions -frerun-cse-after-loop
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fschedule-insns2
# -fsemantic-interposition -fshow-column -fshrink-wrap
# -fshrink-wrap-separate -fsigned-zeros -fsplit-ivs-in-unroller
# -fsplit-wide-types -fssa-backprop -fssa-phiopt -fstack-protector-strong
# -fstdarg-opt -fstore-merging -fstrict-volatile-bitfields -fsync-libcalls
# -fthread-jumps -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp
# -ftree-builtin-call-dce -ftree-ccp -ftree-ch -ftree-coalesce-vars
# -ftree-copy-prop -ftree-cselim -ftree-dce -ftree-dominator-opts
# -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-distribute-patterns
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pre
# -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr
# -ftree-sra -ftree-switch-conversion -ftree-tail-merge -ftree-ter
# -ftree-vrp -funit-at-a-time -fverbose-asm -fwrapv -fwrapv-pointer
# -fzero-initialized-in-bss -m128bit-long-double -m64 -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store -mfentry
# -mfxsr -mglibc -mieee-fp -mindirect-branch-register -mlong-double-80
# -mno-fancy-math-387 -mno-red-zone -mno-sse4 -mpush-args -mrecord-mcount
# -mskip-rax-setup -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
1:	call	__fentry__
	.section __mcount_loc, "a",@progbits
	.quad 1b
	.previous
# kernel/bounds.c:19: 	DEFINE(NR_PAGEFLAGS, __NR_PAGEFLAGS);
#APP
# 19 "kernel/bounds.c" 1
	
.ascii "->NR_PAGEFLAGS $25 __NR_PAGEFLAGS"	#
# 0 "" 2
# kernel/bounds.c:20: 	DEFINE(MAX_NR_ZONES, __MAX_NR_ZONES);
# 20 "kernel/bounds.c" 1
	
.ascii "->MAX_NR_ZONES $5 __MAX_NR_ZONES"	#
# 0 "" 2
# kernel/bounds.c:22: 	DEFINE(NR_CPUS_BITS, ilog2(CONFIG_NR_CPUS));
# 22 "kernel/bounds.c" 1
	
.ascii "->NR_CPUS_BITS $13 ilog2(CONFIG_NR_CPUS)"	#
# 0 "" 2
# kernel/bounds.c:24: 	DEFINE(SPINLOCK_SIZE, sizeof(spinlock_t));
# 24 "kernel/bounds.c" 1
	
.ascii "->SPINLOCK_SIZE $4 sizeof(spinlock_t)"	#
# 0 "" 2
# kernel/bounds.c:28: }
#NO_APP
	xorl	%eax, %eax	#
	jmp	__x86_return_thunk
	.size	main, .-main
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
