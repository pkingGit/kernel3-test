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
	{ 0x5ae39272, "compat_ptr_ioctl" },
	{ 0xe3f1e623, "no_llseek" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0xa9ba4a1, "class_interface_unregister" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x48106fee, "class_destroy" },
	{ 0x177ba742, "scsi_register_interface" },
	{ 0xcee0cc87, "__class_create" },
	{ 0x3fd78f3b, "register_chrdev_region" },
	{ 0xf0bd8450, "scsi_ioctl" },
	{ 0x770a62ae, "blk_trace_startstop" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x3aca0190, "_raw_write_lock_irq" },
	{ 0x13633dad, "blk_trace_remove" },
	{ 0xa3e8d59, "blk_trace_setup" },
	{ 0x548a43d, "scsi_ioctl_block_when_processing_errors" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x56470118, "__warn_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x334da4e, "scsi_command_size_tbl" },
	{ 0x167e7f9d, "__get_user_1" },
	{ 0xc1d5d504, "scsi_cmd_allowed" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x1de4ccb2, "get_sg_io_hdr" },
	{ 0x5a397a37, "blk_rq_map_user_iov" },
	{ 0x155e0a0a, "import_iovec" },
	{ 0x7c56ad8b, "blk_execute_rq_nowait" },
	{ 0xc0934b1f, "blk_rq_map_user" },
	{ 0x88257863, "blk_get_request" },
	{ 0x226d4696, "__module_get" },
	{ 0xbbadb16b, "scsi_block_when_processing_errors" },
	{ 0x2f392431, "scsi_autopm_get_device" },
	{ 0x1d9ab40d, "scsi_device_get" },
	{ 0x20978fb9, "idr_find" },
	{ 0xf541e2e4, "nonseekable_open" },
	{ 0xaf9184a3, "alloc_pages" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1000e51, "schedule" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x3d598bde, "device_destroy" },
	{ 0xa9ca5cb2, "sysfs_remove_link" },
	{ 0x75328114, "cdev_del" },
	{ 0xf9b8bbfa, "sysfs_create_link" },
	{ 0xb10dd8d4, "device_create" },
	{ 0x37d92150, "cdev_add" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x16cb6a90, "radix_tree_preloads" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x954f099c, "idr_preload" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xdda3193e, "cdev_alloc" },
	{ 0xd76716ad, "module_put" },
	{ 0x9ed0358e, "scsi_device_put" },
	{ 0xd47d8201, "scsi_autopm_put_device" },
	{ 0x5ec4aee6, "put_sg_io_hdr" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6b382332, "__scsi_print_sense" },
	{ 0xfbad3cf0, "scsi_normalize_sense" },
	{ 0x3975f4d2, "kill_fasync" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x92997ed8, "_printk" },
	{ 0x7f18d540, "__task_pid_nr_ns" },
	{ 0xa2b07647, "current_task" },
	{ 0x7893dd37, "blk_put_request" },
	{ 0x4555ae70, "blk_rq_unmap_user" },
	{ 0xc8a34b00, "__free_pages" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x807124bd, "fasync_helper" },
	{ 0x37a0cba, "kfree" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xdf2ebb87, "_raw_read_unlock_irqrestore" },
	{ 0xb1342cdb, "_raw_read_lock_irqsave" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa03b6a2b, "sdev_prefix_printk" },
	{ 0xaf3dd7dc, "scsi_logging_level" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xeb078aee, "_raw_write_unlock_irqrestore" },
	{ 0x5021bd81, "_raw_write_lock_irqsave" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "scsi_mod,scsi_common");


MODULE_INFO(srcversion, "3ADD431E649BB09777D669C");
