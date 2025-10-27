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
	{ 0x39c136e4, "hid_add_device" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xf9a482f9, "msleep" },
	{ 0xd36760ef, "__usb_get_extra_descriptor" },
	{ 0xfa355613, "hid_quirks_init" },
	{ 0x754d539c, "strlen" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xe923fbe2, "hid_parse_report" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x69563b8, "usb_kill_urb" },
	{ 0x244a27f2, "usb_deregister_dev" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x2c445244, "input_ff_create" },
	{ 0x267de108, "__hid_request" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x94e15cab, "usb_autopm_get_interface" },
	{ 0x999e8297, "vfree" },
	{ 0xad6115e, "_dev_notice" },
	{ 0x748cd5a2, "usb_unlink_urb" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x5495392, "hid_debug" },
	{ 0xd83e85c0, "hid_input_report" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xe6011b9a, "usb_block_urb" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xf8146ec0, "param_ops_charp" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0xfb578fc5, "memset" },
	{ 0x3cce2970, "usb_string" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa2b07647, "current_task" },
	{ 0xcd30b7e2, "usb_deregister" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x19d52f1f, "hid_quirks_exit" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xa57b02ef, "hid_hw_close" },
	{ 0x2d90596f, "usb_autopm_put_interface_async" },
	{ 0xf9eb30ee, "usb_unpoison_urb" },
	{ 0x807124bd, "fasync_helper" },
	{ 0xb6e9f0fd, "hid_check_keys_pressed" },
	{ 0xef15f6c2, "usb_register_dev" },
	{ 0xe9ba24da, "usb_control_msg" },
	{ 0x15022573, "hid_hw_open" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x6626afca, "down" },
	{ 0x736f6f28, "noop_llseek" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x35f3065a, "hid_set_field" },
	{ 0x38698310, "usb_free_coherent" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x800473f, "__cond_resched" },
	{ 0x5ae39272, "compat_ptr_ioctl" },
	{ 0xe7d08916, "hid_alloc_report_buf" },
	{ 0xc9c5254, "usb_queue_reset_device" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0x458083cf, "usb_submit_urb" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xa916b694, "strnlen" },
	{ 0x5c54c984, "usb_autopm_get_interface_async" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xc00ffa28, "usb_clear_halt" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2671ba5a, "usb_find_interface" },
	{ 0x419c1154, "usb_interrupt_msg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x3d19e5b3, "hid_destroy_device" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x7ccf8287, "__dynamic_dev_dbg" },
	{ 0xcc07b504, "hid_allocate_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xc3612a2c, "usb_autopm_get_interface_no_resume" },
	{ 0x6fa77cff, "usb_autopm_put_interface_no_suspend" },
	{ 0x6affe8e1, "hidinput_count_leds" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x85e71d91, "param_array_ops" },
	{ 0xcf2a6966, "up" },
	{ 0xb29daa06, "usb_register_driver" },
	{ 0x3975f4d2, "kill_fasync" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x41e1f898, "usb_alloc_coherent" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x18db6dd3, "param_ops_uint" },
	{ 0x323cdacc, "usb_free_urb" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x183f7fed, "usb_autopm_put_interface" },
	{ 0xe73ff3ae, "device_set_wakeup_enable" },
	{ 0x3d4db1f9, "usb_alloc_urb" },
	{ 0x92de50d2, "hid_lookup_quirk" },
	{ 0xe47d53da, "hid_output_report" },
};

MODULE_INFO(depends, "hid,usbcore");

MODULE_ALIAS("usb:v*p*d*dc*dsc*dp*ic03isc*ip*in*");
