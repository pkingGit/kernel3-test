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
	{ 0x6f964f27, "pci_write_config_dword" },
	{ 0xf9a482f9, "msleep" },
	{ 0x3f670570, "pcim_enable_device" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x754d539c, "strlen" },
	{ 0xdf721637, "snd_ac97_tune_hardware" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0x90e7e473, "snd_pcm_period_elapsed" },
	{ 0xfb8094e0, "snd_pcm_hw_constraint_msbits" },
	{ 0x447c43b4, "pcim_iomap" },
	{ 0xf5995852, "seq_printf" },
	{ 0xd70f899a, "snd_pci_quirk_lookup" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x23fdaf2d, "snd_devm_card_new" },
	{ 0x6ca98bf3, "param_ops_bool" },
	{ 0x9e913c1, "snd_pcm_alt_chmaps" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x282275af, "snd_pcm_hw_constraint_integer" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x15f0c039, "snd_ac97_pcm_assign" },
	{ 0xc4714407, "snd_card_disconnect" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xf13689ec, "snd_ac97_get_short_name" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xf8146ec0, "param_ops_charp" },
	{ 0x87c4ccfd, "pci_set_master" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0xa0691578, "snd_pcm_set_managed_buffer_all" },
	{ 0xb19b445, "ioread8" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xf7a6bece, "snd_pcm_hw_constraint_list" },
	{ 0xc6fd8a31, "snd_pcm_set_ops" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0xca1b2641, "param_ops_bint" },
	{ 0x380b04bf, "snd_ac97_suspend" },
	{ 0x998669fa, "snd_ac97_update_power" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0x6d78ae9, "snd_ac97_pcm_double_rate_rules" },
	{ 0xa916b694, "strnlen" },
	{ 0xa9c046fd, "snd_devm_alloc_pages" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x848d372e, "iowrite8" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xf3d5446d, "pci_read_config_dword" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x595b192, "pci_unregister_driver" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x79d8a63d, "snd_ac97_bus" },
	{ 0x7ccf8287, "__dynamic_dev_dbg" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x20e42c59, "snd_ac97_mixer" },
	{ 0xa21a09cc, "snd_ac97_update_bits" },
	{ 0x2dc54062, "snd_card_rw_proc_new" },
	{ 0x5d499747, "snd_ac97_set_rate" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x37b55602, "snd_card_free_on_error" },
	{ 0x69acdf38, "memcpy" },
	{ 0xd29480df, "pci_request_regions" },
	{ 0xbdfa0237, "__pci_register_driver" },
	{ 0xd5380500, "snd_ac97_pcm_open" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x4507a670, "snd_card_register" },
	{ 0x2500b329, "snd_pcm_add_chmap_ctls" },
	{ 0x229247f9, "snd_pcm_new" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x7f8e7c9d, "snd_ac97_resume" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x69255f54, "snd_pcm_hw_limit_rates" },
	{ 0xea67b6e8, "snd_ac97_pcm_close" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xc1514a3b, "free_irq" },
};

MODULE_INFO(depends, "snd-ac97-codec,snd-pcm,snd");

MODULE_ALIAS("pci:v00008086d00002415sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002425sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002445sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002485sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000024C5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000024D5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000025A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000266Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000027DEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002698sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00007195sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00007012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000001B1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000003Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000006Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000059sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000008Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000000DAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000000EAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000026Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001022d0000746Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001022d00007445sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010B9d00005455sv*sd*bc*sc*i*");
