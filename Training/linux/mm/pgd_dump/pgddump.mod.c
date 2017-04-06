#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x26717fb7, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xd598bed2, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xac27409d, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x8a4f9a63, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x6826a531, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x577b2c7d, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x440e87b4, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x26daeb08, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x208601c5, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x3ed60467, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xdf607a5e, __VMLINUX_SYMBOL_STR(kmap) },
	{ 0xa99c70fb, __VMLINUX_SYMBOL_STR(mem_map) },
	{ 0x86e3c9f7, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "250BB0BDAB22D11AD631E5D");
