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
	{ 0x1942c88d, "usb_hcd_pci_pm_ops" },
	{ 0xc34b32f9, "usb_hcd_pci_shutdown" },
	{ 0xcf7a17b6, "usb_hcd_pci_remove" },
	{ 0x595b192, "pci_unregister_driver" },
	{ 0xbdfa0237, "__pci_register_driver" },
	{ 0x4a92be6f, "ohci_resume" },
	{ 0x3f73c22f, "ohci_suspend" },
	{ 0x39e6a351, "ohci_init_driver" },
	{ 0x92997ed8, "_printk" },
	{ 0x19a304ba, "usb_disabled" },
	{ 0xac0c1c5f, "pci_dev_put" },
	{ 0x9e91a6c5, "pci_get_slot" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0xb3d281a, "ohci_restart" },
	{ 0xfa17bee2, "device_init_wakeup" },
	{ 0x7ccf8287, "__dynamic_dev_dbg" },
	{ 0xd87fc0a0, "usb_amd_prefetch_quirk" },
	{ 0xaf4014ff, "usb_amd_quirk_pll_check" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x4b80206b, "ohci_setup" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe7ad1912, "pci_match_id" },
	{ 0xae85d8d, "usb_hcd_pci_probe" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "usbcore,ohci-hcd");

MODULE_ALIAS("pci:v*d*sv*sd*bc0Csc03i10*");
MODULE_ALIAS("pci:v0000104Ad0000CC01sv*sd*bc*sc*i*");
