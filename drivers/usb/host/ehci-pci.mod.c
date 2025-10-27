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
	{ 0x595b192, "pci_unregister_driver" },
	{ 0xbdfa0237, "__pci_register_driver" },
	{ 0x8d23c587, "ehci_suspend" },
	{ 0x2daf1e19, "ehci_init_driver" },
	{ 0x92997ed8, "_printk" },
	{ 0x19a304ba, "usb_disabled" },
	{ 0x4716f2c1, "device_set_wakeup_capable" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xef9c5900, "pci_write_config_byte" },
	{ 0x33832c7, "usb_amd_hang_symptom_quirk" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0xf3d5446d, "pci_read_config_dword" },
	{ 0xc104203e, "pci_read_config_word" },
	{ 0xaf4014ff, "usb_amd_quirk_pll_check" },
	{ 0x445cfe57, "dma_set_coherent_mask" },
	{ 0x2c1ba508, "pci_read_config_byte" },
	{ 0xe33666ce, "ehci_setup" },
	{ 0x64a23486, "pci_find_capability" },
	{ 0x4dd00fa9, "ehci_resume" },
	{ 0x7ccf8287, "__dynamic_dev_dbg" },
	{ 0x7c2eec1b, "pci_set_mwi" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xae85d8d, "usb_hcd_pci_probe" },
	{ 0xe7ad1912, "pci_match_id" },
	{ 0xcf7a17b6, "usb_hcd_pci_remove" },
	{ 0x248ec72b, "pci_clear_mwi" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "usbcore,ehci-hcd");

MODULE_ALIAS("pci:v*d*sv*sd*bc0Csc03i20*");
MODULE_ALIAS("pci:v0000104Ad0000CC00sv*sd*bc*sc*i*");
