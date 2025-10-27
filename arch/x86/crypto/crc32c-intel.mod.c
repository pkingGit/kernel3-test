#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe28fa882, "module_layout" },
	{ 0xa92ec74, "boot_cpu_data" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x4ed0842b, "crypto_unregister_shash" },
	{ 0xc42bee3c, "crypto_register_shash" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x73dd54eb, "irq_fpu_usable" },
	{ 0x305a916c, "__x86_indirect_thunk_rdi" },
	{ 0xcea381dd, "x86_match_cpu" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("cpu:type:x86,ven*fam*mod*:feature:*0094*");
