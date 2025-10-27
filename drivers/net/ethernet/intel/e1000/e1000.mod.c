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
	{ 0xe9d1bdc7, "netdev_info" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x31027c7a, "ethtool_op_get_ts_info" },
	{ 0xc767aa7, "pcix_set_mmrbc" },
	{ 0xf9a482f9, "msleep" },
	{ 0x4212cb34, "put_devmap_managed_page" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x349cba85, "strchr" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x2a873af6, "napi_disable" },
	{ 0x754d539c, "strlen" },
	{ 0x8b22e7c0, "napi_schedule_prep" },
	{ 0x8f996a30, "ethtool_convert_legacy_u32_to_link_mode" },
	{ 0x7c50592a, "dma_set_mask" },
	{ 0x91a488ac, "__netdev_alloc_frag_align" },
	{ 0x19a16549, "pci_disable_device" },
	{ 0x4ea25709, "dql_reset" },
	{ 0xaded5b86, "netif_carrier_on" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xe6df6305, "netif_carrier_off" },
	{ 0x56470118, "__warn_printk" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xaf9184a3, "alloc_pages" },
	{ 0x52cf8daf, "__dev_kfree_skb_any" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x5fc67252, "ioread16_rep" },
	{ 0x2b67ff5a, "pci_enable_wake" },
	{ 0x999e8297, "vfree" },
	{ 0x95a214fc, "dma_free_attrs" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x8cc79cab, "iowrite16_rep" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x445cfe57, "dma_set_coherent_mask" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4122a8e, "__dynamic_netdev_dbg" },
	{ 0x6cf1c74c, "pcix_get_mmrbc" },
	{ 0x2ea49498, "skb_trim" },
	{ 0xb47cca30, "csum_ipv6_magic" },
	{ 0xd6b2ed99, "__pskb_pull_tail" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x87c4ccfd, "pci_set_master" },
	{ 0xcaba5e2b, "netif_schedule_queue" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0xfb578fc5, "memset" },
	{ 0x3295459f, "dma_sync_single_for_cpu" },
	{ 0x2479df2e, "netif_tx_wake_queue" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa2b07647, "current_task" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xde80cd09, "ioremap" },
	{ 0xa00aca2a, "dql_completed" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x38eda5c6, "free_netdev" },
	{ 0x9166fada, "strncpy" },
	{ 0x7b5b4a7e, "register_netdev" },
	{ 0x66bbf85, "napi_enable" },
	{ 0xc104203e, "pci_read_config_word" },
	{ 0x284e2acd, "dma_alloc_attrs" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2072c2cb, "kfree_skb_reason" },
	{ 0x659f84c2, "netif_napi_add" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xac5eee76, "softnet_data" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0xe523ad75, "synchronize_irq" },
	{ 0xa4edcce9, "build_skb" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7c2eec1b, "pci_set_mwi" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x2362ec65, "pci_select_bars" },
	{ 0x55e31703, "ethtool_convert_link_mode_to_legacy_u32" },
	{ 0x7ced2eea, "netif_device_attach" },
	{ 0x483d9ece, "napi_gro_receive" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x2480f447, "netif_device_detach" },
	{ 0x46976d0, "__alloc_skb" },
	{ 0xbce7a435, "__napi_schedule" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x88e1d0f0, "page_frag_free" },
	{ 0x92997ed8, "_printk" },
	{ 0x26b5d91c, "napi_complete_done" },
	{ 0xaa58f955, "dma_map_page_attrs" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd9bd5e63, "eth_type_trans" },
	{ 0x32a67d76, "dev_driver_string" },
	{ 0x3c401bf8, "pskb_expand_head" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x3fcf25a6, "netdev_err" },
	{ 0x595b192, "pci_unregister_driver" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x9f67d772, "pci_ioremap_bar" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x3e0ffbe1, "pci_set_power_state" },
	{ 0x6888506a, "netdev_warn" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xb2d06da0, "eth_validate_addr" },
	{ 0x248ec72b, "pci_clear_mwi" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0x8aacfa38, "___pskb_trim" },
	{ 0x85e71d91, "param_array_ops" },
	{ 0xedc03953, "iounmap" },
	{ 0xa45ac92a, "dma_sync_single_for_device" },
	{ 0xbdfa0237, "__pci_register_driver" },
	{ 0x15af7f4, "system_state" },
	{ 0x2754aa61, "dma_unmap_page_attrs" },
	{ 0xe3b0cdf7, "napi_get_frags" },
	{ 0x93c55ef7, "unregister_netdev" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xa2ad4bd7, "consume_skb" },
	{ 0xcd30f506, "pci_enable_device_mem" },
	{ 0xfebd65d2, "__napi_alloc_skb" },
	{ 0x508fa3c, "skb_tstamp_tx" },
	{ 0x6bf9bc3e, "skb_put" },
	{ 0xff89fc4a, "pci_enable_device" },
	{ 0x3330ae4b, "pci_wake_from_d3" },
	{ 0x3bd8a2f, "pci_release_selected_regions" },
	{ 0x462a8e2b, "pci_request_selected_regions" },
	{ 0x18db6dd3, "param_ops_uint" },
	{ 0x663b929a, "skb_copy_bits" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x5b95c3d6, "__put_page" },
	{ 0xaa2b1461, "napi_gro_frags" },
	{ 0x9cebd5f7, "__skb_pad" },
	{ 0xe73ff3ae, "device_set_wakeup_enable" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x4c30856f, "pci_save_state" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x56d61659, "alloc_etherdev_mqs" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00008086d00001000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001004sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001008sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001009sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000100Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000100Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000100Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000100Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001010sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001013sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001015sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001016sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001017sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001019sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000101Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000101Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000101Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001026sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001027sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001075sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001076sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001077sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001078sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001079sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000107Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000107Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000107Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000108Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001099sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010B5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002E6Esv*sd*bc*sc*i*");
