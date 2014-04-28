/*
 * PPS kernel consumer API
 *
 * Copyright (C) 2009-2010   Alexander Gordeev <lasaine@lvk.cs.msu.su>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/spinlock.h>
#include <linux/pps_kernel.h>

#include "kc.h"


DEFINE_SPINLOCK(pps_kc_hardpps_lock);
struct pps_device *pps_kc_hardpps_dev;	
int pps_kc_hardpps_mode;		

int pps_kc_bind(struct pps_device *pps, struct pps_bind_args *bind_args)
{
	
	spin_lock_irq(&pps_kc_hardpps_lock);

	if (bind_args->edge == 0)
		if (pps_kc_hardpps_dev == pps) {
			pps_kc_hardpps_mode = 0;
			pps_kc_hardpps_dev = NULL;
			spin_unlock_irq(&pps_kc_hardpps_lock);
			dev_info(pps->dev, "unbound kernel"
					" consumer\n");
		} else {
			spin_unlock_irq(&pps_kc_hardpps_lock);
			dev_err(pps->dev, "selected kernel consumer"
					" is not bound\n");
			return -EINVAL;
		}
	else
		if (pps_kc_hardpps_dev == NULL ||
				pps_kc_hardpps_dev == pps) {
			pps_kc_hardpps_mode = bind_args->edge;
			pps_kc_hardpps_dev = pps;
			spin_unlock_irq(&pps_kc_hardpps_lock);
			dev_info(pps->dev, "bound kernel consumer: "
				"edge=0x%x\n", bind_args->edge);
		} else {
			spin_unlock_irq(&pps_kc_hardpps_lock);
			dev_err(pps->dev, "another kernel consumer"
					" is already bound\n");
			return -EINVAL;
		}

	return 0;
}

void pps_kc_remove(struct pps_device *pps)
{
	spin_lock_irq(&pps_kc_hardpps_lock);
	if (pps == pps_kc_hardpps_dev) {
		pps_kc_hardpps_mode = 0;
		pps_kc_hardpps_dev = NULL;
		spin_unlock_irq(&pps_kc_hardpps_lock);
		dev_info(pps->dev, "unbound kernel consumer"
				" on device removal\n");
	} else
		spin_unlock_irq(&pps_kc_hardpps_lock);
}

void pps_kc_event(struct pps_device *pps, struct pps_event_time *ts,
		int event)
{
	unsigned long flags;

	
	spin_lock_irqsave(&pps_kc_hardpps_lock, flags);
	if (pps == pps_kc_hardpps_dev && event & pps_kc_hardpps_mode)
		hardpps(&ts->ts_real, &ts->ts_raw);
	spin_unlock_irqrestore(&pps_kc_hardpps_lock, flags);
}
