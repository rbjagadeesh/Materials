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
	{ 0x380122c1, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x65e14d2d, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x61fe91dc, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x264586be, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x1757ab0d, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x32f82cba, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0xb09e4fb2, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xeaa8ce49, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x5d16d48e, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "758264B5EEDA0F0F584A152");
