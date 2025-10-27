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
	{ 0xe597a0c4, "ata_dummy_port_ops" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0xc5e0a0a1, "ata_port_freeze" },
	{ 0xf9a482f9, "msleep" },
	{ 0x66ebcc5, "__pm_runtime_idle" },
	{ 0xf8f3a0fb, "ata_ratelimit" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0xe3d491b2, "dev_attr_sw_activity" },
	{ 0x8565e305, "ata_port_printk" },
	{ 0xfa489cc7, "sata_pmp_error_handler" },
	{ 0xfdbda607, "sata_link_scr_lpm" },
	{ 0xfef58e0d, "sata_pmp_qc_defer_cmd_switch" },
	{ 0x87b8798d, "sg_next" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x6ca98bf3, "param_ops_bool" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xb1efc319, "__pm_runtime_resume" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x1c266484, "ata_port_desc" },
	{ 0x32875f4c, "pv_ops" },
	{ 0xf5b74fe6, "dev_attr_ncq_prio_enable" },
	{ 0x4b2bd8a5, "dev_attr_em_message" },
	{ 0x42635d55, "pm_suspend_global_flags" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4fdc945d, "sata_deb_timing_normal" },
	{ 0x46e8fe96, "sata_pmp_port_ops" },
	{ 0x19e0aa5d, "ata_ehi_push_desc" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0xdedcd690, "ata_dev_set_feature" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x37c31fc5, "ata_dev_printk" },
	{ 0xd8b16e26, "ata_wait_register" },
	{ 0x1fcfda83, "acpi_storage_d3" },
	{ 0x83996077, "ata_std_qc_defer" },
	{ 0xc70e28f4, "ata_host_start" },
	{ 0xce6aede2, "ata_link_abort" },
	{ 0x3bed5c72, "dev_attr_unload_heads" },
	{ 0x5532f01e, "ata_msleep" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xcccfb2fa, "sata_deb_timing_hotplug" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0xfad6be84, "devm_kfree" },
	{ 0xf7d810e5, "ata_ehi_clear_desc" },
	{ 0x6ca9b327, "sata_link_hardreset" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0x5ec62549, "ata_dev_classify" },
	{ 0xdceb127f, "ata_host_activate" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7646cee, "ata_tf_to_fis" },
	{ 0xfab835ef, "ata_host_register" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x5067b728, "dev_attr_ncq_prio_supported" },
	{ 0x2d948835, "dev_attr_em_message_type" },
	{ 0x53dc17be, "sata_lpm_ignore_phy_events" },
	{ 0x32a67d76, "dev_driver_string" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd198d21f, "ata_link_printk" },
	{ 0xf3d0aa5e, "ata_wait_after_reset" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x51dfb661, "ata_qc_complete_multiple" },
	{ 0xe69c59f, "ata_link_next" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x69acdf38, "memcpy" },
	{ 0x9384cd49, "ata_tf_from_fis" },
	{ 0x6128b5fc, "__printk_ratelimit" },
	{ 0x52f4c885, "ata_std_postreset" },
	{ 0xe0fb5da2, "dmam_alloc_attrs" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x4e7716d7, "dev_attr_link_power_management_policy" },
	{ 0xa758bfb8, "ata_port_abort" },
	{ 0xedaf7efe, "devm_kmalloc" },
	{ 0x7d67799e, "devm_request_threaded_irq" },
	{ 0x7ebd3e4c, "sata_async_notification" },
};

MODULE_INFO(depends, "libata");

