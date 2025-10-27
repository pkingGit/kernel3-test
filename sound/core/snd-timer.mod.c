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
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x8ac0b4fd, "snd_register_device" },
	{ 0xa0eb4545, "param_ops_int" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xf8f2a4eb, "snd_kill_fasync" },
	{ 0xd72811db, "stream_open" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x2f91d3e9, "snd_device_initialize" },
	{ 0xe3f1e623, "no_llseek" },
	{ 0xf5995852, "seq_printf" },
	{ 0x56470118, "__warn_printk" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xdd64e639, "strscpy" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x5af762f1, "snd_fasync_free" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x4ef05047, "snd_device_new" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa2b07647, "current_task" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x9ec6ca96, "ktime_get_real_ts64" },
	{ 0x6f4a3134, "snd_unregister_device" },
	{ 0x8df3789f, "snd_oss_info_register" },
	{ 0x3971b4df, "snd_ecards_limit" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0xd76716ad, "module_put" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xa916b694, "strnlen" },
	{ 0xf49af822, "put_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x1000e51, "schedule" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xbbd3601a, "get_device" },
	{ 0xcd91b127, "system_highpri_wq" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xc7aa1442, "snd_fasync_helper" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x37a0cba, "kfree" },
	{ 0xf721baad, "snd_info_free_entry" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xbac4015f, "dev_set_name" },
	{ 0x5e515be6, "ktime_get_ts64" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x95abf2ae, "snd_info_create_module_entry" },
	{ 0xa418510c, "snd_info_register" },
	{ 0x6557e2fd, "try_module_get" },
};

MODULE_INFO(depends, "snd");

