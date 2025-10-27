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
	{ 0x53fa2554, "platform_driver_unregister" },
	{ 0x4bd10965, "__platform_driver_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x66b01bc6, "__cpuhp_setup_state" },
	{ 0xb071bcc3, "powercap_register_control_type" },
	{ 0xa92ec74, "boot_cpu_data" },
	{ 0xcea381dd, "x86_match_cpu" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa5e55057, "rdmsrl_safe_on_cpu" },
	{ 0x6228c21f, "smp_call_function_single" },
	{ 0x95085f89, "rapl_add_package" },
	{ 0xbf8cd18f, "rapl_remove_package" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x21bcc594, "rapl_find_package_domain" },
	{ 0x9ee636e, "powercap_unregister_control_type" },
	{ 0xa7bfae19, "__cpuhp_remove_state" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x32875f4c, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "intel_rapl_common");

MODULE_ALIAS("platform:intel_rapl_msr");
