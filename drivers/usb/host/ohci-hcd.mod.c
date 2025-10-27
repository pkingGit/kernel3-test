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
	{ 0x2f2c95c4, "flush_work" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x6d2a1569, "usb_root_hub_lost_power" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xf9a482f9, "msleep" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xe01b0ece, "debugfs_create_dir" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0xf932e3d1, "usb_debug_root" },
	{ 0xe0fcc94f, "usb_hcd_poll_rh_status" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x87b8798d, "sg_next" },
	{ 0x60ba97c, "gen_pool_free_owner" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x6ca98bf3, "param_ops_bool" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x29a726a7, "usb_hcd_giveback_urb" },
	{ 0x95a214fc, "dma_free_attrs" },
	{ 0x9e8bfef8, "debugfs_create_file" },
	{ 0xb5aa7165, "dma_pool_destroy" },
	{ 0xb9b9df41, "usb_amd_dev_put" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x10ecc52c, "usb_amd_quirk_pll_enable" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0xe5f2249a, "usb_hcd_link_urb_to_ep" },
	{ 0xa4de7f83, "default_llseek" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x3d210724, "gen_pool_dma_zalloc_align" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0xdc825d6c, "usb_amd_quirk_pll_disable" },
	{ 0xdc3cafce, "debugfs_remove" },
	{ 0x284e2acd, "dma_alloc_attrs" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x7e64181d, "usb_calc_bus_time" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x2f7754a8, "dma_pool_free" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0xe523ad75, "synchronize_irq" },
	{ 0xc17515d7, "usb_hcds_loaded" },
	{ 0x7f10789a, "usb_hcd_check_unlink_urb" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x92997ed8, "_printk" },
	{ 0x953bf357, "sb800_prefetch" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x678b96ec, "dma_pool_alloc" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x7ccf8287, "__dynamic_dev_dbg" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x19a304ba, "usb_disabled" },
	{ 0x37a0cba, "kfree" },
	{ 0x96848186, "scnprintf" },
	{ 0xada31e57, "gen_pool_dma_alloc_align" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xe1fce28f, "usb_hc_died" },
	{ 0x50775a61, "usb_hcd_unlink_urb_from_ep" },
	{ 0x3b59f23d, "usb_hcd_resume_root_hub" },
	{ 0xadf4059f, "dma_pool_create" },
	{ 0x4716f2c1, "device_set_wakeup_capable" },
	{ 0xc1514a3b, "free_irq" },
};

MODULE_INFO(depends, "usbcore,usb-common");

