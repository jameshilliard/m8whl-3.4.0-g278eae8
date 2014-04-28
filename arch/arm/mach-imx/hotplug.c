/*
 * Copyright 2011 Freescale Semiconductor, Inc.
 * Copyright 2011 Linaro Ltd.
 *
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

#include <linux/errno.h>
#include <asm/cacheflush.h>
#include <mach/common.h>

int platform_cpu_kill(unsigned int cpu)
{
	return 1;
}

void platform_cpu_die(unsigned int cpu)
{
	flush_cache_all();
	imx_enable_cpu(cpu, false);
	cpu_do_idle();

	
	panic("cpu %d unexpectedly exit from shutdown\n", cpu);
}

int platform_cpu_disable(unsigned int cpu)
{
	return cpu == 0 ? -EPERM : 0;
}
