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
	{ 0xd0abc618, "hid_unregister_driver" },
	{ 0x1468b251, "__hid_register_driver" },
	{ 0xe1a7ab95, "bus_for_each_drv" },
	{ 0x1b810ac5, "hid_bus_type" },
	{ 0x2c4f0114, "hid_hw_start" },
	{ 0x78bccc9c, "hid_open_report" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xd45ec68d, "hid_match_device" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "hid");

MODULE_ALIAS("hid:b*g*v*p*");
