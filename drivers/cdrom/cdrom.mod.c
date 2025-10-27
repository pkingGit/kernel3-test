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
	{ 0x6a449c4f, "register_sysctl_table" },
	{ 0xa8181adf, "proc_dointvec" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6ca98bf3, "param_ops_bool" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x7d033ebb, "invalidate_bdev" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0xfb578fc5, "memset" },
	{ 0xa2b07647, "current_task" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0x319d493d, "proc_dostring" },
	{ 0xc6cbbc89, "capable" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xd691c6a9, "unregister_sysctl_table" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0x96848186, "scnprintf" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
};

MODULE_INFO(depends, "");

