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
	{ 0xe5c253ed, "kmem_cache_destroy" },
	{ 0x8049b1aa, "simple_pin_fs" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0x53b954a2, "up_read" },
	{ 0x94ec1938, "generic_file_llseek" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x9e655f4c, "inode_permission" },
	{ 0x754d539c, "strlen" },
	{ 0xc6328912, "get_tree_single" },
	{ 0x3f767694, "simple_release_fs" },
	{ 0xbabe0bb1, "_copy_from_iter" },
	{ 0xe6360488, "generic_delete_inode" },
	{ 0xd9b85ef6, "lockref_get" },
	{ 0x4a779454, "dput" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x7f9d92de, "inc_nlink" },
	{ 0x5d9d88d9, "init_user_ns" },
	{ 0x364850b1, "down_write_killable" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xac56ee25, "d_add" },
	{ 0xa05aac1c, "generic_read_dir" },
	{ 0x999e8297, "vfree" },
	{ 0x32875f4c, "pv_ops" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x668b19a1, "down_read" },
	{ 0xaa586a1b, "d_delete" },
	{ 0xea258e9f, "ram_aops" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x830c00ce, "sysfs_remove_mount_point" },
	{ 0xfa4602c6, "kern_path" },
	{ 0xfb578fc5, "memset" },
	{ 0x9f9a4365, "kill_litter_super" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x47f4b57e, "kmem_cache_free" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x587b0954, "kvasprintf" },
	{ 0xce807a25, "up_write" },
	{ 0x57bc19d2, "down_write" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0xd76716ad, "module_put" },
	{ 0xc6cbbc89, "capable" },
	{ 0x49dc09b, "kmem_cache_alloc" },
	{ 0xeae5b5b6, "simple_unlink" },
	{ 0x29912596, "simple_setattr" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x8b8059bd, "in_group_p" },
	{ 0x61cdfdd1, "d_drop" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x7f8948d5, "simple_get_link" },
	{ 0x4f670d79, "path_put" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xea17fe4, "kmem_cache_create" },
	{ 0xbad0336a, "register_filesystem" },
	{ 0x148653, "vsnprintf" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xd476141, "sysfs_create_mount_point" },
	{ 0xe953b21f, "get_next_ino" },
	{ 0xf3d37d1b, "kernel_kobj" },
	{ 0x5c492149, "iput" },
	{ 0x37a0cba, "kfree" },
	{ 0x615b1acd, "iunique" },
	{ 0x69acdf38, "memcpy" },
	{ 0x53856c4c, "current_time" },
	{ 0x3bbae66b, "fsnotify" },
	{ 0x6cf85a61, "always_delete_dentry" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x9a487c1b, "d_make_root" },
	{ 0x28252c4c, "simple_statfs" },
	{ 0xa186e975, "d_alloc_name" },
	{ 0xa33eb387, "unregister_filesystem" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x24ace766, "new_inode" },
	{ 0xcc2b9a3, "free_inode_nonrcu" },
	{ 0xab15be35, "_copy_to_iter" },
	{ 0x4ef04ae9, "d_instantiate" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6557e2fd, "try_module_get" },
	{ 0xace13eb0, "simple_rmdir" },
	{ 0xc836c066, "__d_drop" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BC1DB3508C53C477B672C9F");
