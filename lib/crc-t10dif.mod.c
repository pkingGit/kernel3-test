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
	{ 0x2d3385d3, "system_wq" },
	{ 0x2b20b489, "crypto_alloc_shash" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x4cce3be6, "crypto_shash_update" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x9879932b, "crypto_register_notifier" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x765ff474, "crc_t10dif_generic" },
	{ 0x34c3aaf9, "crypto_destroy_tfm" },
	{ 0xb912560d, "static_key_disable" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x710c73b6, "crypto_unregister_notifier" },
};

MODULE_INFO(depends, "crct10dif_common");

