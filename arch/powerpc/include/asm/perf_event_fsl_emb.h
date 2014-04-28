/*
 * Performance event support - Freescale embedded specific definitions.
 *
 * Copyright 2008-2009 Paul Mackerras, IBM Corporation.
 * Copyright 2010 Freescale Semiconductor, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License, or (at your option) any later version.
 */

#include <linux/types.h>
#include <asm/hw_irq.h>

#define MAX_HWEVENTS 4

#define FSL_EMB_EVENT_VALID      1
#define FSL_EMB_EVENT_RESTRICTED 2

#define FSL_EMB_EVENT_THRESHMUL  0x0000070000000000ULL
#define FSL_EMB_EVENT_THRESH     0x0000003f00000000ULL

struct fsl_emb_pmu {
	const char	*name;
	int		n_counter; 

	int		n_restricted;

	
	u64		(*xlate_event)(u64 event_id);

	int		n_generic;
	int		*generic_events;
	int		(*cache_events)[PERF_COUNT_HW_CACHE_MAX]
			       [PERF_COUNT_HW_CACHE_OP_MAX]
			       [PERF_COUNT_HW_CACHE_RESULT_MAX];
};

int register_fsl_emb_pmu(struct fsl_emb_pmu *);
