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
	{ 0xe3f1e623, "no_llseek" },
	{ 0xdd55f9f4, "input_unregister_handler" },
	{ 0x64635299, "input_register_handler" },
	{ 0xa2eeb372, "input_open_device" },
	{ 0xd72811db, "stream_open" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0x5297e987, "input_ff_upload" },
	{ 0x59b2adbf, "input_ff_effect_from_user" },
	{ 0xd8cef6e1, "clear_user" },
	{ 0x9878e62b, "input_grab_device" },
	{ 0x91886a7, "input_ff_erase" },
	{ 0x2688ec10, "bitmap_zalloc" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x20dbf27, "bitmap_alloc" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0xda0ee8d8, "input_release_device" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x92997ed8, "_printk" },
	{ 0xd05b480e, "cdev_device_add" },
	{ 0x65f84319, "cdev_init" },
	{ 0x9aea948e, "input_register_handle" },
	{ 0x618a3a47, "device_initialize" },
	{ 0x1cc9e567, "input_class" },
	{ 0xbbd3601a, "get_device" },
	{ 0xbac4015f, "dev_set_name" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x183bd601, "kmem_cache_alloc_trace" },
	{ 0xd1c97624, "kmalloc_caches" },
	{ 0xc0ff21c1, "input_get_new_minor" },
	{ 0xbd235a7a, "input_unregister_handle" },
	{ 0x5cf53ce2, "input_free_minor" },
	{ 0x614c5b0c, "cdev_device_del" },
	{ 0xf2d44480, "input_close_device" },
	{ 0xdb39608e, "input_flush_device" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x3975f4d2, "kill_fasync" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1000e51, "schedule" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xf7455c16, "input_event_to_user" },
	{ 0x32875f4c, "pv_ops" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x800473f, "__cond_resched" },
	{ 0x8fdb768d, "input_inject_event" },
	{ 0xe233762a, "input_event_from_user" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0xa2b07647, "current_task" },
	{ 0x37a0cba, "kfree" },
	{ 0xf49af822, "put_device" },
	{ 0xe6db6ca3, "input_set_keycode" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x51c79f41, "input_get_keycode" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x754d539c, "strlen" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0x8b4253f0, "input_get_timestamp" },
	{ 0x807124bd, "fasync_helper" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("input:b*v*p*e*-e*k*r*a*m*l*s*f*w*");
