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
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc90359e8, "i2c_add_adapter" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x3d8a4e64, "i2c_add_numbered_adapter" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x760a0f4f, "yield" },
};

MODULE_INFO(depends, "");

