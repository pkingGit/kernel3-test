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
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x595b192, "pci_unregister_driver" },
	{ 0xbdfa0237, "__pci_register_driver" },
	{ 0x9cca4f84, "pci_write_config_word" },
	{ 0xb5697eca, "pci_bus_read_config_byte" },
	{ 0xc104203e, "pci_read_config_word" },
	{ 0xad6115e, "_dev_notice" },
	{ 0xef9c5900, "pci_write_config_byte" },
	{ 0x2c1ba508, "pci_read_config_byte" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xedc03953, "iounmap" },
	{ 0x3ada9e06, "acpi_check_region" },
	{ 0xb58d1e82, "set_primary_fwnode" },
	{ 0x183bb932, "acpi_find_child_device" },
	{ 0xc90359e8, "i2c_add_adapter" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x968f6b33, "is_acpi_device_node" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xde80cd09, "ioremap" },
	{ 0x85bd1608, "__request_region" },
	{ 0x77358855, "iomem_resource" },
	{ 0x848d372e, "iowrite8" },
	{ 0xb19b445, "ioread8" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0x7ccf8287, "__dynamic_dev_dbg" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x37a0cba, "kfree" },
	{ 0x16f160d6, "i2c_del_adapter" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00008086d00007113sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000719Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001055d00009463sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004353sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004363sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004372sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004385sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001022d0000780Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001022d0000790Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001D94d0000790Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001166d00000200sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001166d00000201sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001166d00000203sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001166d00000205sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001166d00000408sv*sd*bc*sc*i*");
