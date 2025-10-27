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
	{ 0xc37c8de7, "acpi_bus_register_driver" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0x50877b9, "dmi_first_match" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0xab6ba49, "proc_create_single_data" },
	{ 0xf5995852, "seq_printf" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xd71e52e2, "remove_proc_entry" },
	{ 0x979b1fb5, "acpi_bus_unregister_driver" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x51921f02, "input_event" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xc36a3bd4, "__acpi_handle_debug" },
	{ 0x91430a4d, "proc_mkdir" },
	{ 0x169938c1, "__sysfs_match_string" },
	{ 0xd6285e90, "acpi_pm_wakeup_event" },
	{ 0x36fe96a4, "input_set_capability" },
	{ 0x1a45cb6c, "acpi_disabled" },
	{ 0xfa17bee2, "device_init_wakeup" },
	{ 0x77456e0a, "acpi_root_dir" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x862ff56e, "input_register_device" },
	{ 0x92997ed8, "_printk" },
	{ 0x470e739e, "input_free_device" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0x74754435, "acpi_bus_generate_netlink_event" },
	{ 0x37a0cba, "kfree" },
	{ 0x394511e5, "input_unregister_device" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x287b8037, "param_ops_ulong" },
	{ 0x6cbf5ef2, "acpi_device_hid" },
	{ 0x2d4feddb, "input_allocate_device" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:PNP0C0D:*");
MODULE_ALIAS("acpi*:PNP0C0E:*");
MODULE_ALIAS("acpi*:LNXSLPBN:*");
MODULE_ALIAS("acpi*:PNP0C0C:*");
MODULE_ALIAS("acpi*:LNXPWRBN:*");
