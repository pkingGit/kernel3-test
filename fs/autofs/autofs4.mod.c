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
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xd75fbcb9, "drop_nlink" },
	{ 0xa4129a0e, "put_pid" },
	{ 0x349cba85, "strchr" },
	{ 0x6ce9e1ff, "get_task_pid" },
	{ 0x754d539c, "strlen" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0xd0bd974a, "path_is_mountpoint" },
	{ 0xb1147773, "from_kuid_munged" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0x31252152, "pid_vnr" },
	{ 0x83047a26, "seq_puts" },
	{ 0xd9b85ef6, "lockref_get" },
	{ 0x4a779454, "dput" },
	{ 0xf5995852, "seq_printf" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x44e9a829, "match_token" },
	{ 0x7f9d92de, "inc_nlink" },
	{ 0xad2fd17e, "dentry_open" },
	{ 0x5d9d88d9, "init_user_ns" },
	{ 0xa843805a, "get_unused_fd_flags" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x85df9b6c, "strsep" },
	{ 0xac56ee25, "d_add" },
	{ 0xa05aac1c, "generic_read_dir" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x354fd1ab, "mount_nodev" },
	{ 0x7145aceb, "path_get" },
	{ 0x5a9d4ae7, "may_umount" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xdf6a03fc, "from_kgid_munged" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0x3cf932bd, "make_kgid" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x8b987f20, "dcache_dir_lseek" },
	{ 0x6ef87d8b, "misc_register" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0xfa4602c6, "kern_path" },
	{ 0x9f9a4365, "kill_litter_super" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa2b07647, "current_task" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x41aa24c9, "set_nlink" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x736f6f28, "noop_llseek" },
	{ 0xbb60a4b2, "dentry_path_raw" },
	{ 0xa07a37f0, "memchr" },
	{ 0x4e3567f7, "match_int" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xa349761f, "fput" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xb6fde909, "close_fd" },
	{ 0x7f18d540, "__task_pid_nr_ns" },
	{ 0x800473f, "__cond_resched" },
	{ 0xa7e98a50, "path_has_submounts" },
	{ 0xc6cbbc89, "capable" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x99723d4a, "make_kuid" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x1000e51, "schedule" },
	{ 0x6d334118, "__get_user_8" },
	{ 0xfb6af58d, "recalc_sigpending" },
	{ 0x92997ed8, "_printk" },
	{ 0x61cdfdd1, "d_drop" },
	{ 0xb04f0e3a, "may_umount_tree" },
	{ 0x3f4547a7, "put_unused_fd" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd6eaaea1, "full_name_hash" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x4f670d79, "path_put" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xfe42b7a6, "simple_empty" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x93520c75, "dcache_readdir" },
	{ 0xbad0336a, "register_filesystem" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x333bd6b0, "d_lookup" },
	{ 0x9b62e252, "init_pid_ns" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x57222863, "find_get_pid" },
	{ 0x94781858, "dcache_dir_open" },
	{ 0xe953b21f, "get_next_ino" },
	{ 0x4515d59b, "dcache_dir_close" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0x37a0cba, "kfree" },
	{ 0x8811cc7a, "follow_up" },
	{ 0x69acdf38, "memcpy" },
	{ 0x53856c4c, "current_time" },
	{ 0x4dd25d1f, "fd_install" },
	{ 0x3ee26048, "fget" },
	{ 0x9a487c1b, "d_make_root" },
	{ 0x8f956bb0, "__kernel_write" },
	{ 0x28252c4c, "simple_statfs" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xa33eb387, "unregister_filesystem" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x24ace766, "new_inode" },
	{ 0x63237d88, "follow_down_one" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x61bdbab5, "clear_inode" },
	{ 0xd3136983, "misc_deregister" },
	{ 0xe63dbc5c, "clear_nlink" },
	{ 0xe914e41e, "strcpy" },
};

MODULE_INFO(depends, "");

