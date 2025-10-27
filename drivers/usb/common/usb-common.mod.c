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
	{ 0xe01b0ece, "debugfs_create_dir" },
	{ 0x81188c30, "match_string" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xdc3cafce, "debugfs_remove" },
	{ 0x67a7dd09, "device_property_read_string" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa5810f3e, "led_trigger_unregister_simple" },
	{ 0xa96e9fe1, "led_trigger_register_simple" },
	{ 0x28c2d019, "led_trigger_blink_oneshot" },
	{ 0x656e4a6e, "snprintf" },
};

MODULE_INFO(depends, "");

