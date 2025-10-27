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
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x754d539c, "strlen" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0x6193260e, "snd_info_create_card_entry" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xf5995852, "seq_printf" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x6ca98bf3, "param_ops_bool" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9e913c1, "snd_pcm_alt_chmaps" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xf9c0b663, "strlcat" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0x4ef05047, "snd_device_new" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xea792415, "device_register" },
	{ 0xa7dfa917, "_snd_ctl_add_follower" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xdc54f3bf, "ac97_bus_type" },
	{ 0xc104203e, "pci_read_config_word" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0x77b28e06, "snd_ctl_boolean_mono_info" },
	{ 0xcc6a729f, "snd_ctl_enum_info" },
	{ 0x2e4b8956, "snd_pcm_hw_rule_add" },
	{ 0x238ff72a, "snd_ctl_make_virtual_master" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xa916b694, "strnlen" },
	{ 0x364d3282, "snd_component_add" },
	{ 0x4e1b99f, "snd_pcm_std_chmaps" },
	{ 0x19015935, "snd_ctl_remove_id" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xb733be7d, "snd_ctl_new1" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xd3d0fcc7, "snd_ctl_find_id" },
	{ 0x7ccf8287, "__dynamic_dev_dbg" },
	{ 0x4cda566, "snd_interval_refine" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0xf721baad, "snd_info_free_entry" },
	{ 0x469bacb5, "device_unregister" },
	{ 0x4b2c98d8, "snd_ctl_add" },
	{ 0xbac4015f, "dev_set_name" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xe914e41e, "strcpy" },
};

MODULE_INFO(depends, "snd,snd-pcm,ac97_bus");

