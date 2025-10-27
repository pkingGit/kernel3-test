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
	{ 0xf2ebe768, "device_remove_file" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xf9a482f9, "msleep" },
	{ 0x82a1d164, "_dev_printk" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x754d539c, "strlen" },
	{ 0xd7e0c4e1, "device_add_groups" },
	{ 0xa9d5fa99, "serio_unregister_driver" },
	{ 0x18bd0124, "ps2_handle_ack" },
	{ 0xf2916332, "ps2_sendbyte" },
	{ 0x2da1a32a, "ps2_handle_response" },
	{ 0xaf3222d2, "input_mt_report_finger_count" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xefe78f6, "input_alloc_absinfo" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xa1270a09, "ps2_end_command" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xaf6dd5f9, "i2c_for_each_dev" },
	{ 0xd6b53a4d, "__ps2_command" },
	{ 0x6ca98bf3, "param_ops_bool" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x95d41d61, "i2c_verify_adapter" },
	{ 0x85df9b6c, "strsep" },
	{ 0xca3a2b59, "serio_interrupt" },
	{ 0x29ad8e33, "x86_hyper_type" },
	{ 0xad6115e, "_dev_notice" },
	{ 0xa6b03579, "ps2_drain" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xfa617a44, "sysfs_remove_group" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xcafa7abd, "input_mt_report_pointer_emulation" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x63cfccfd, "input_set_abs_params" },
	{ 0x51921f02, "input_event" },
	{ 0x77f149c1, "serio_unregister_child_port" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0x1c35e2ae, "__serio_register_driver" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x6a6e05bf, "kstrtou8" },
	{ 0x3bccbe35, "i2c_bus_type" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0xb7195a28, "sysfs_create_group" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0x5a921311, "strncmp" },
	{ 0x36fe96a4, "input_set_capability" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x244cc138, "input_mt_init_slots" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x5b65b91c, "serio_close" },
	{ 0xe6bfda42, "i2c_unregister_device" },
	{ 0x52c92550, "serio_open" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0x42160169, "flush_workqueue" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x9eacf8a5, "kstrndup" },
	{ 0x9500debf, "device_create_file" },
	{ 0x800473f, "__cond_resched" },
	{ 0x24fc8c1f, "i2c_adapter_type" },
	{ 0x2594ef01, "fwnode_create_software_node" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x2fcca219, "bus_register_notifier" },
	{ 0x45ea544f, "i2c_new_scanned_device" },
	{ 0xda269dbb, "ps2_command" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x862ff56e, "input_register_device" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x39a87d88, "pm_wakeup_dev_event" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x7154cb5f, "ps2_sliced_command" },
	{ 0x92997ed8, "_printk" },
	{ 0x470e739e, "input_free_device" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xdc92667a, "input_mt_drop_unused" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2e65dffb, "ps2_init" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0x7ccf8287, "__dynamic_dev_dbg" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x1d341231, "serio_reconnect" },
	{ 0x3b7b0512, "__serio_register_port" },
	{ 0x685a7f62, "device_remove_groups" },
	{ 0x37a0cba, "kfree" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x394511e5, "input_unregister_device" },
	{ 0x15ff9edf, "serio_rescan" },
	{ 0xef881b4b, "input_mt_report_slot_state" },
	{ 0x2be37089, "ps2_cmd_aborted" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x9eb426ff, "input_mt_sync_frame" },
	{ 0x974f3d8, "i2c_client_type" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xfe969979, "bus_unregister_notifier" },
	{ 0x18db6dd3, "param_ops_uint" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xfbe0fad8, "ps2_begin_command" },
	{ 0x3e8fc1ed, "input_mt_assign_slots" },
	{ 0x2d4feddb, "input_allocate_device" },
	{ 0x81e6b37f, "dmi_get_system_info" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("serio:ty01pr*id*ex*");
MODULE_ALIAS("serio:ty05pr*id*ex*");
