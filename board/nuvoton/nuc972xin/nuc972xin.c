// SPDX-License-Identifier: GPL-2.0+
/*
 *
 * Copyright (C) 2011-2015 
 */

#include <common.h>
#include <init.h>
#include <asm/global_data.h>
#include <asm/io.h>
#include <linux/delay.h>
#include <asm/arch/register.h>


DECLARE_GLOBAL_DATA_PTR;

int board_early_init_f(void)
{
	writel(readl(REG_PCLKEN0) | 0x10000, REG_PCLKEN0);   // UART clk
	writel(readl(REG_PCLKEN0) | 0x100, REG_PCLKEN0);   // Timer clk
#ifdef CONFIG_NUC970_GPIO
	writel(readl(REG_PCLKEN0) | 0x8, REG_PCLKEN0);   // GPIO clk
#endif

	return 0;
}

int board_init(void)
{
	/* adress of boot parameters */
	gd->bd->bi_boot_params = CONFIG_SYS_SDRAM_BASE + 0x100;
	
	gd->bd->bi_arch_number = 0;	

	return 0;
}

