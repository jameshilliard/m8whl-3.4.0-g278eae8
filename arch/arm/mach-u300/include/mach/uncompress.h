/*
 * arch/arm/mach-u300/include/mach/uncompress.h
 *
 * Copyright (C) 2003 ARM Limited
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#define AMBA_UART_DR	(*(volatile unsigned char *)0xc0013000)
#define AMBA_UART_LCRH	(*(volatile unsigned char *)0xc001302C)
#define AMBA_UART_CR	(*(volatile unsigned char *)0xc0013030)
#define AMBA_UART_FR	(*(volatile unsigned char *)0xc0013018)

static inline void putc(int c)
{
	while (AMBA_UART_FR & (1 << 5))
		barrier();

	AMBA_UART_DR = c;
}

static inline void flush(void)
{
	while (AMBA_UART_FR & (1 << 3))
		barrier();
}

#define arch_decomp_setup()
#define arch_decomp_wdog()