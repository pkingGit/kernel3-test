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
	{ 0xcc28e02, "ahci_sdev_attrs" },
	{ 0x413d8b5a, "ahci_shost_attrs" },
	{ 0xf170a766, "ata_scsi_unlock_native_capacity" },
	{ 0x8c450c44, "ata_std_bios_param" },
	{ 0x9260cfe5, "ata_scsi_dma_need_drain" },
	{ 0x12d9bbc9, "ata_scsi_change_queue_depth" },
	{ 0x2d883505, "ata_scsi_slave_destroy" },
	{ 0x48461ec1, "ata_scsi_slave_config" },
	{ 0x8456293e, "ata_scsi_ioctl" },
	{ 0x43c50139, "ata_scsi_queuecmd" },
	{ 0xe99027fc, "ahci_ops" },
	{ 0xf3ca30eb, "ata_pci_remove_one" },
	{ 0x595b192, "pci_unregister_driver" },
	{ 0xbdfa0237, "__pci_register_driver" },
	{ 0x87b8798d, "sg_next" },
	{ 0xba156513, "ahci_fill_cmd_slot" },
	{ 0x69acdf38, "memcpy" },
	{ 0x7646cee, "ata_tf_to_fis" },
	{ 0x92997ed8, "_printk" },
	{ 0x46419dbf, "pcim_pin_device" },
	{ 0x38db3238, "pci_enable_msi" },
	{ 0xea50dad3, "ahci_ignore_sss" },
	{ 0x4508fa80, "ata_print_version" },
	{ 0x527f1663, "ahci_host_activate" },
	{ 0x87c4ccfd, "pci_set_master" },
	{ 0xd913a3f1, "ahci_print_info" },
	{ 0xc104203e, "pci_read_config_word" },
	{ 0x445cfe57, "dma_set_coherent_mask" },
	{ 0x7c50592a, "dma_set_mask" },
	{ 0xe597a0c4, "ata_dummy_port_ops" },
	{ 0x3e2432b3, "ata_port_pbar_desc" },
	{ 0x18b9ad5b, "ata_host_alloc_pinfo" },
	{ 0x31a0ba18, "ahci_set_em_messages" },
	{ 0x4e6cacf0, "ahci_save_initial_config" },
	{ 0x67a0b883, "pcim_iomap_table" },
	{ 0xa42fddd6, "pcim_iomap_regions_request_all" },
	{ 0x3f670570, "pcim_enable_device" },
	{ 0xdc00f270, "_dev_warn" },
	{ 0x1a5cc3d0, "_dev_info" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd9f22a7d, "ahci_port_resume" },
	{ 0xe0fb5da2, "dmam_alloc_attrs" },
	{ 0xedaf7efe, "devm_kmalloc" },
	{ 0x9384cd49, "ata_tf_from_fis" },
	{ 0xa7a2bece, "_dev_err" },
	{ 0xd68fbe0d, "ata_pci_device_suspend" },
	{ 0xe0986ecd, "ahci_init_controller" },
	{ 0x2c6fba11, "ahci_reset_controller" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xf9d2d6d2, "ata_host_resume" },
	{ 0xebcbcfa4, "ata_pci_device_do_resume" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "libahci,libata");

MODULE_ALIAS("pci:v00001191d0000000Dsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "48C5CEBBCA963AF26AABBF5");
