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
	{ 0x6d2a1569, "usb_root_hub_lost_power" },
	{ 0xf2ebe768, "device_remove_file" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xe765ba5f, "pci_bus_type" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xf9a482f9, "msleep" },
	{ 0xb0482da9, "platform_unregister_drivers" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xe01b0ece, "debugfs_create_dir" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x754d539c, "strlen" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0xf932e3d1, "usb_debug_root" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0xe0fcc94f, "usb_hcd_poll_rh_status" },
	{ 0x56470118, "__warn_printk" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x87b8798d, "sg_next" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x6ca98bf3, "param_ops_bool" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x29a726a7, "usb_hcd_giveback_urb" },
	{ 0x999e8297, "vfree" },
	{ 0x95a214fc, "dma_free_attrs" },
	{ 0x9e8bfef8, "debugfs_create_file" },
	{ 0xb5aa7165, "dma_pool_destroy" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xb9b9df41, "usb_amd_dev_put" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x8b8def1d, "usb_hub_clear_tt_buffer" },
	{ 0x10ecc52c, "usb_amd_quirk_pll_enable" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0xe5f2249a, "usb_hcd_link_urb_to_ep" },
	{ 0xa4de7f83, "default_llseek" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0xdc825d6c, "usb_amd_quirk_pll_disable" },
	{ 0xbc9b8588, "ehci_cf_port_reset_rwsem" },
	{ 0xdc3cafce, "debugfs_remove" },
	{ 0x284e2acd, "dma_alloc_attrs" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x7e64181d, "usb_calc_bus_time" },
	{ 0x42cfe7ea, "xen_dbgp_external_startup" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x2f7754a8, "dma_pool_free" },
	{ 0x9154d530, "usb_hcd_end_port_resume" },
	{ 0xce807a25, "up_write" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0x57bc19d2, "down_write" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0xe523ad75, "synchronize_irq" },
	{ 0xc17515d7, "usb_hcds_loaded" },
	{ 0x9500debf, "device_create_file" },
	{ 0x93743d6f, "xen_dbgp_reset_prep" },
	{ 0x7f10789a, "usb_hcd_check_unlink_urb" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x92997ed8, "_printk" },
	{ 0x85f2ca19, "__platform_register_drivers" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xf3d5446d, "pci_read_config_dword" },
	{ 0x678b96ec, "dma_pool_alloc" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x7ccf8287, "__dynamic_dev_dbg" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x19a304ba, "usb_disabled" },
	{ 0x37a0cba, "kfree" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x96848186, "scnprintf" },
	{ 0xe1fce28f, "usb_hc_died" },
	{ 0x9a3d3ecc, "usb_hcd_start_port_resume" },
	{ 0x50775a61, "usb_hcd_unlink_urb_from_ep" },
	{ 0x3b59f23d, "usb_hcd_resume_root_hub" },
	{ 0xadf4059f, "dma_pool_create" },
	{ 0x18db6dd3, "param_ops_uint" },
	{ 0x2cd57384, "usb_for_each_dev" },
};

MODULE_INFO(depends, "usbcore,usb-common");

