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
	{ 0x2d3385d3, "system_wq" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x1c58427f, "acpi_remove_notify_handler" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0x9939eba0, "backlight_unregister_notifier" },
	{ 0x170ddf79, "acpi_install_notify_handler" },
	{ 0x63b67f56, "thermal_cooling_device_unregister" },
	{ 0xdb0d519e, "backlight_device_register" },
	{ 0x72578e69, "acpi_bus_get_device" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xd92deb6b, "acpi_evaluate_object" },
	{ 0x979b1fb5, "acpi_bus_unregister_driver" },
	{ 0x6ca98bf3, "param_ops_bool" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x509034b8, "acpi_notifier_call_chain" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x17d93b8d, "acpi_match_device_ids" },
	{ 0x51921f02, "input_event" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xc36a3bd4, "__acpi_handle_debug" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x2f384db3, "acpi_is_video_device" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0x47094ade, "backlight_device_get_by_type" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xd8df08ac, "acpi_handle_printk" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x72b185eb, "acpi_get_pci_dev" },
	{ 0x9cc4f70a, "register_pm_notifier" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb4043948, "acpi_execute_simple_method" },
	{ 0x1a45cb6c, "acpi_disabled" },
	{ 0xa9ca5cb2, "sysfs_remove_link" },
	{ 0xb7c0f443, "sort" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0x32e6f1a0, "acpi_video_backlight_string" },
	{ 0xcd8ce890, "acpi_format_exception" },
	{ 0xf9b8bbfa, "sysfs_create_link" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x862ff56e, "input_register_device" },
	{ 0x92997ed8, "_printk" },
	{ 0x470e739e, "input_free_device" },
	{ 0xf3d5446d, "pci_read_config_dword" },
	{ 0xdc512134, "backlight_register_notifier" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfe9ebbbb, "acpi_osi_is_win8" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0x7ccf8287, "__dynamic_dev_dbg" },
	{ 0xe58c3bd5, "thermal_cooling_device_register" },
	{ 0x37a0cba, "kfree" },
	{ 0x394511e5, "input_unregister_device" },
	{ 0x5aa70984, "acpi_reduced_hardware" },
	{ 0x7681946c, "unregister_pm_notifier" },
	{ 0x7d12d76d, "acpi_get_parent" },
	{ 0x95a42295, "pci_get_device" },
	{ 0xac0c1c5f, "pci_dev_put" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x29ac20ca, "backlight_force_update" },
	{ 0xec2b8a42, "acpi_walk_namespace" },
	{ 0xa622cc29, "backlight_device_unregister" },
	{ 0x509b64ea, "acpi_has_method" },
	{ 0x6cbf5ef2, "acpi_device_hid" },
	{ 0x2d4feddb, "input_allocate_device" },
	{ 0x81e6b37f, "dmi_get_system_info" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:LNXVIDEO:*");
