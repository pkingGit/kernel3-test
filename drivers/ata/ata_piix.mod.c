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
	{ 0x38df75a9, "ata_bmdma32_port_ops" },
	{ 0xef1fec41, "ata_cable_40wire" },
	{ 0x4e7716d7, "dev_attr_link_power_management_policy" },
	{ 0x1e547dd1, "ata_common_sdev_attrs" },
	{ 0xf170a766, "ata_scsi_unlock_native_capacity" },
	{ 0x8c450c44, "ata_std_bios_param" },
	{ 0x9260cfe5, "ata_scsi_dma_need_drain" },
	{ 0x2d883505, "ata_scsi_slave_destroy" },
	{ 0x48461ec1, "ata_scsi_slave_config" },
	{ 0x8456293e, "ata_scsi_ioctl" },
	{ 0x43c50139, "ata_scsi_queuecmd" },
	{ 0xeb12c693, "sata_std_hardreset" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x595b192, "pci_unregister_driver" },
	{ 0xbdfa0237, "__pci_register_driver" },
	{ 0xdb370fd6, "ata_slave_link_init" },
	{ 0x67a0b883, "pcim_iomap_table" },
	{ 0x70246520, "pcim_iomap_regions" },
	{ 0xf9a482f9, "msleep" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0x8bafe40d, "pci_intx" },
	{ 0x714b6c95, "pci_iounmap" },
	{ 0xb5e6c90, "pci_iomap" },
	{ 0xe32bfd65, "ata_pci_sff_activate_host" },
	{ 0xe818b32b, "ata_bmdma_interrupt" },
	{ 0x87c4ccfd, "pci_set_master" },
	{ 0x95a42295, "pci_get_device" },
	{ 0x96848186, "scnprintf" },
	{ 0x4508fa80, "ata_print_version" },
	{ 0xeeb9b09c, "ata_pci_bmdma_prepare_host" },
	{ 0xf3d5446d, "pci_read_config_dword" },
	{ 0xedaf7efe, "devm_kmalloc" },
	{ 0x3f670570, "pcim_enable_device" },
	{ 0x50877b9, "dmi_first_match" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x6d785749, "ata_sff_prereset" },
	{ 0xdaad6796, "pci_test_config_bits" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xef9c5900, "pci_write_config_byte" },
	{ 0x2c1ba508, "pci_read_config_byte" },
	{ 0x9cca4f84, "pci_write_config_word" },
	{ 0xc104203e, "pci_read_config_word" },
	{ 0xc572e06d, "ata_pio_need_iordy" },
	{ 0xd9d4e129, "ata_bmdma_status" },
	{ 0xfdbda607, "sata_link_scr_lpm" },
	{ 0x3fa476f6, "ata_bmdma_port_start" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xf3ca30eb, "ata_pci_remove_one" },
	{ 0x6f964f27, "pci_write_config_dword" },
	{ 0x4c30856f, "pci_save_state" },
	{ 0xce1d79f7, "ata_pci_device_do_suspend" },
	{ 0x78ddb76b, "dmi_match" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0x9fba00, "ata_host_suspend" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0xebcbcfa4, "ata_pci_device_do_resume" },
	{ 0xf9d2d6d2, "ata_host_resume" },
	{ 0xdd72f85c, "pci_reenable_device" },
	{ 0xe47a0659, "pci_restore_state" },
	{ 0x3e0ffbe1, "pci_set_power_state" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "libata");

MODULE_ALIAS("pci:v00008086d00007010sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00007111sv000015ADsd00001976bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00007111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00007199sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00007601sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000084CAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002411sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002421sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000244Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000244Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000248Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000248Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000024C1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000024CAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000024CBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000024DBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000245Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000025A2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000266Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000027DFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000269Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002850sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000024D1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000024DFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000025A3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000025B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002651sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002652sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002653sv*sd*bc01sc01i*");
MODULE_ALIAS("pci:v00008086d000027C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000027C4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002680sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002820sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002825sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002828sv0000106Bsd000000A0bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002828sv0000106Bsd000000A1bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002828sv0000106Bsd000000A3bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002828sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002920sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002921sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002926sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002928sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000292Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000292Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00005028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003A00sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003A06sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003A20sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003A26sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003B20sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003B21sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003B26sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003B28sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003B2Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003B2Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001C00sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001C01sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001C08sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001C09sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D00sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D08sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001E00sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001E01sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001E08sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001E09sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008C00sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008C01sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008C08sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008C09sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009C00sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009C01sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009C08sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009C09sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002326sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001F20sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001F21sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001F30sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001F31sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008D00sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008D08sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008D60sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008D68sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000F20sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000F21sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000023A6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008C88sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008C89sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008C80sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008C81sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "0F0C45275478B664DD3F898");
