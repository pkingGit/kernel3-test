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
	{ 0x979b1fb5, "acpi_bus_unregister_driver" },
	{ 0xc37c8de7, "acpi_bus_register_driver" },
	{ 0xb4577003, "acpi_dev_present" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0x1a45cb6c, "acpi_disabled" },
	{ 0x973fa82e, "register_acpi_notifier" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xadcefbad, "power_supply_register" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xc36a3bd4, "__acpi_handle_debug" },
	{ 0xf9a482f9, "msleep" },
	{ 0x509034b8, "acpi_notifier_call_chain" },
	{ 0x74754435, "acpi_bus_generate_netlink_event" },
	{ 0x169d3cb3, "kobject_uevent" },
	{ 0x22f12fc1, "power_supply_get_drvdata" },
	{ 0xd8df08ac, "acpi_handle_printk" },
	{ 0xcd8ce890, "acpi_format_exception" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0x37a0cba, "kfree" },
	{ 0x7023bea8, "unregister_acpi_notifier" },
	{ 0xc4152111, "power_supply_unregister" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:ACPI0003:*");
