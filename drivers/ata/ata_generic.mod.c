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
	{ 0x1e547dd1, "ata_common_sdev_attrs" },
	{ 0xf170a766, "ata_scsi_unlock_native_capacity" },
	{ 0x8c450c44, "ata_std_bios_param" },
	{ 0x9260cfe5, "ata_scsi_dma_need_drain" },
	{ 0x2d883505, "ata_scsi_slave_destroy" },
	{ 0x48461ec1, "ata_scsi_slave_config" },
	{ 0x8456293e, "ata_scsi_ioctl" },
	{ 0x43c50139, "ata_scsi_queuecmd" },
	{ 0xfff2b034, "ata_bmdma_port_ops" },
	{ 0x4a372449, "ata_cable_unknown" },
	{ 0x5982605e, "ata_pci_device_resume" },
	{ 0xd68fbe0d, "ata_pci_device_suspend" },
	{ 0xf3ca30eb, "ata_pci_remove_one" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x595b192, "pci_unregister_driver" },
	{ 0xbdfa0237, "__pci_register_driver" },
	{ 0x4b51f74c, "ata_xfer_mode2mask" },
	{ 0x43f56e82, "ata_xfer_mode2shift" },
	{ 0x24f63dcf, "ata_xfer_mask2mode" },
	{ 0x37c31fc5, "ata_dev_printk" },
	{ 0xc48b7ccf, "ata_mode_string" },
	{ 0x1b5059ce, "ata_id_xfermask" },
	{ 0xbe13f8a3, "ata_dev_next" },
	{ 0xb19b445, "ioread8" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9cca4f84, "pci_write_config_word" },
	{ 0x1625657e, "ata_pci_bmdma_clear_simplex" },
	{ 0x46419dbf, "pcim_pin_device" },
	{ 0x3f670570, "pcim_enable_device" },
	{ 0xf3d5446d, "pci_read_config_dword" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x74347ace, "ata_pci_bmdma_init_one" },
	{ 0xc104203e, "pci_read_config_word" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "libata");

MODULE_ALIAS("pci:v00001042d00003020sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009412d00006565sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001060d00000101sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001060d0000886Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001060d0000673Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00003388d00008013sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00000561sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001045d0000C558sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000016CAd00000001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001179d00000101sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001179d00000102sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001179d00000103sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001179d00000105sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d*sv*sd*bc01sc01i*");
MODULE_ALIAS("pci:v*d*sv*sd*bc01sc01i*");

MODULE_INFO(srcversion, "31299D553C1274E39FAADC4");
