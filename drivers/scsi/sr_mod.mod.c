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
	{ 0x134ae2c4, "scsi_set_medium_removal" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0x75862516, "blk_queue_rq_timeout" },
	{ 0xf9a482f9, "msleep" },
	{ 0xfbad3cf0, "scsi_normalize_sense" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x91a61468, "cdrom_number_of_slots" },
	{ 0xcf548b9, "blkdev_compat_ptr_ioctl" },
	{ 0x7893dd37, "blk_put_request" },
	{ 0x548a43d, "scsi_ioctl_block_when_processing_errors" },
	{ 0x981e197b, "unregister_cdrom" },
	{ 0x33034458, "blk_dump_rq_flags" },
	{ 0x87b8798d, "sg_next" },
	{ 0x39d89dbe, "scsi_free_sgtables" },
	{ 0x22e54d0f, "scmd_printk" },
	{ 0x720a27a7, "__register_blkdev" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x336f0517, "cdrom_open" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x2f392431, "scsi_autopm_get_device" },
	{ 0x43e26709, "scsi_alloc_sgtables" },
	{ 0x4555ae70, "blk_rq_unmap_user" },
	{ 0x80781fb2, "__alloc_disk_node" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x8643e565, "cdrom_release" },
	{ 0xaf0768de, "del_gendisk" },
	{ 0xaf3dd7dc, "scsi_logging_level" },
	{ 0x273a314c, "__scsi_execute" },
	{ 0xbb550bd6, "driver_unregister" },
	{ 0xa03b6a2b, "sdev_prefix_printk" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x39372900, "cdrom_get_media_event" },
	{ 0x880da8bc, "set_capacity" },
	{ 0xb1925c54, "bdev_check_media_change" },
	{ 0xc0934b1f, "blk_rq_map_user" },
	{ 0xdf97a89d, "cdrom_check_events" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0xb5a459dc, "unregister_blkdev" },
	{ 0x6fc0b919, "cdrom_get_last_written" },
	{ 0x9ed0358e, "scsi_device_put" },
	{ 0xc6cbbc89, "capable" },
	{ 0xdb97efef, "blk_execute_rq" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf0bd8450, "scsi_ioctl" },
	{ 0x493b2b38, "put_disk" },
	{ 0x604a5482, "scsi_register_driver" },
	{ 0xbbadb16b, "scsi_block_when_processing_errors" },
	{ 0x74f5dad, "scsi_test_unit_ready" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x37a0cba, "kfree" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0xb3614992, "cdrom_ioctl" },
	{ 0x1580424f, "blk_pm_runtime_init" },
	{ 0xf6520fae, "register_cdrom" },
	{ 0x73d2d622, "device_add_disk" },
	{ 0x1d9ab40d, "scsi_device_get" },
	{ 0xd47d8201, "scsi_autopm_put_device" },
	{ 0x7d290a97, "blk_queue_logical_block_size" },
	{ 0x88257863, "blk_get_request" },
	{ 0x3daaf643, "scsi_mode_sense" },
};

MODULE_INFO(depends, "scsi_mod,scsi_common,cdrom");

