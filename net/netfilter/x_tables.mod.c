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
	{ 0xa24f23d8, "__request_module" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x349cba85, "strchr" },
	{ 0x37be85b9, "proc_create_seq_private" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x754d539c, "strlen" },
	{ 0xf5995852, "seq_printf" },
	{ 0xd71e52e2, "remove_proc_entry" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0x2a48ea6f, "proc_set_user" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x999e8297, "vfree" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xdd64e639, "strscpy" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x3cf932bd, "make_kgid" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x697f167e, "PDE_DATA" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x21cb8003, "unregister_pernet_subsys" },
	{ 0xb44e18ea, "audit_enabled" },
	{ 0xa2b07647, "current_task" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x9166fada, "strncpy" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0x800473f, "__cond_resched" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0xd76716ad, "module_put" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x618911fc, "numa_node" },
	{ 0xa916b694, "strnlen" },
	{ 0x99723d4a, "make_kuid" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x276d8017, "register_pernet_subsys" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x9b3f26bc, "proc_create_net_data" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xff1e9dd8, "seq_list_start" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xe7d4daac, "seq_list_next" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x9968aacb, "__audit_log_nfcfg" },
	{ 0xd8cef6e1, "clear_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6557e2fd, "try_module_get" },
};

MODULE_INFO(depends, "");

