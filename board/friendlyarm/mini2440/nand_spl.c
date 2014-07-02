#include <common.h>


#ifdef CONFIG_NAND_SPL
void __weak board_init_f(ulong dummy)
{
	unsigned int i;
        unsigned int stack = 0x33f80000;

	__asm__ __volatile__ (
		"mov sp, %0"
		::"r"(stack)
		:"sp");
	nand_boot();
}
#endif

