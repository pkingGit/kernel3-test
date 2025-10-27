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
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x3d598bde, "device_destroy" },
	{ 0x15375632, "__register_chrdev" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x32875f4c, "pv_ops" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x736f6f28, "noop_llseek" },
	{ 0xb10dd8d4, "device_create" },
	{ 0xd76716ad, "module_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x37a0cba, "kfree" },
	{ 0x48106fee, "class_destroy" },
	{ 0xcee0cc87, "__class_create" },
	{ 0x6557e2fd, "try_module_get" },
};

MODULE_INFO(depends, "");

