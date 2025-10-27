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
	{ 0x2d3385d3, "system_wq" },
	{ 0x414e7d12, "bus_register" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0x65f84319, "cdev_init" },
	{ 0xe01b0ece, "debugfs_create_dir" },
	{ 0x510caa5f, "single_open" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0xc6818247, "single_release" },
	{ 0x83047a26, "seq_puts" },
	{ 0xe3f1e623, "no_llseek" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xf5995852, "seq_printf" },
	{ 0x56470118, "__warn_printk" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x6c18b184, "kobject_set_name" },
	{ 0x1d07e365, "memdup_user_nul" },
	{ 0x6ca98bf3, "param_ops_bool" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x85df9b6c, "strsep" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x9e8bfef8, "debugfs_create_file" },
	{ 0xdd64e639, "strscpy" },
	{ 0x196ff43d, "seq_read" },
	{ 0x2509945a, "kthread_create_on_node" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x20463df4, "wait_for_completion_killable" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xddd00ca5, "kthread_stop" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xdc3cafce, "debugfs_remove" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x69239d8a, "bus_unregister" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc6cbbc89, "capable" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xa916b694, "strnlen" },
	{ 0xf49af822, "put_device" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x587b60db, "debugfs_create_devm_seqfile" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xd05b480e, "cdev_device_add" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8ca353d7, "wake_up_process" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xbbd3601a, "get_device" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1fe4eb9c, "seq_lseek" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0xb71589f0, "skip_spaces" },
	{ 0x618a3a47, "device_initialize" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x614c5b0c, "cdev_device_del" },
	{ 0xa6257a2f, "complete" },
	{ 0xbac4015f, "dev_set_name" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
};

MODULE_INFO(depends, "");

