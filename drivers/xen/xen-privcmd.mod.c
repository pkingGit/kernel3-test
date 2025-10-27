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
	{ 0x45d14bdf, "hypercall_page" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xba8725af, "vm_map_pages_zero" },
	{ 0xed22bde0, "xen_alloc_unpopulated_pages" },
	{ 0x4b931968, "xen_features" },
	{ 0x8d6aff89, "__put_user_nocheck_4" },
	{ 0x7cdbd57a, "__mmap_lock_do_trace_released" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x5667e297, "__tracepoint_mmap_lock_start_locking" },
	{ 0xaf9184a3, "alloc_pages" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xf803c9df, "xen_remap_pfn" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xd7e21ac6, "__mmap_lock_do_trace_start_locking" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x6ef87d8b, "misc_register" },
	{ 0x8e9483f8, "xen_unmap_domain_gfn_range" },
	{ 0xa2b07647, "current_task" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0xe8d07cd, "apply_to_page_range" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xce807a25, "up_write" },
	{ 0x57bc19d2, "down_write" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0xcc896ed9, "xen_remap_vma_range" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xeae30d1e, "xen_free_unpopulated_pages" },
	{ 0x68d03588, "find_vma" },
	{ 0xc8a34b00, "__free_pages" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6d334118, "__get_user_8" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xfe2b333a, "__tracepoint_mmap_lock_released" },
	{ 0x4195b37f, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0x37a0cba, "kfree" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x17f6c3e9, "__mmap_lock_do_trace_acquire_returned" },
	{ 0x87706d4e, "__put_user_nocheck_8" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x18db6dd3, "param_ops_uint" },
	{ 0xb285b8f8, "xen_in_preemptible_hcall" },
	{ 0x3d4d9e67, "unpin_user_pages_dirty_lock" },
	{ 0xd3136983, "misc_deregister" },
	{ 0xd8cef6e1, "clear_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x362f8dd0, "xen_xlate_remap_gfn_array" },
	{ 0xb712f77d, "pin_user_pages_fast" },
};

MODULE_INFO(depends, "");

