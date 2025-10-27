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
	{ 0x53fa2554, "platform_driver_unregister" },
	{ 0x4bd10965, "__platform_driver_register" },
	{ 0x470e739e, "input_free_device" },
	{ 0x862ff56e, "input_register_device" },
	{ 0x2d4feddb, "input_allocate_device" },
	{ 0x394511e5, "input_unregister_device" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x75943e25, "i8253_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");

