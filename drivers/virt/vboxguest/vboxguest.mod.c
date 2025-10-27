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
	{ 0xf2ebe768, "device_remove_file" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x77358855, "iomem_resource" },
	{ 0x39461d6a, "in_egroup_p" },
	{ 0x19a16549, "pci_disable_device" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xaf9184a3, "alloc_pages" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x63cfccfd, "input_set_abs_params" },
	{ 0x51921f02, "input_event" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x6ef87d8b, "misc_register" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xfb578fc5, "memset" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x2e91d8a3, "from_kuid" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa2b07647, "current_task" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xaa074440, "vmap" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x36fe96a4, "input_set_capability" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x9500debf, "device_create_file" },
	{ 0x800473f, "__cond_resched" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xc8a34b00, "__free_pages" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x862ff56e, "input_register_device" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x39651f1b, "__devm_request_region" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x595b192, "pci_unregister_driver" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x37a0cba, "kfree" },
	{ 0x94961283, "vunmap" },
	{ 0x6ec8622d, "devm_input_allocate_device" },
	{ 0xa380f656, "devm_ioremap" },
	{ 0xbdfa0237, "__pci_register_driver" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x7098599a, "vmalloc_to_page" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xff89fc4a, "pci_enable_device" },
	{ 0xedaf7efe, "devm_kmalloc" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xd3136983, "misc_deregister" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xaa0c318b, "vscnprintf" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xc1514a3b, "free_irq" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000080EEd0000CAFEsv00000000sd00000000bc*sc*i*");
