/*
 * Header file describing the internal (inter-module) DHD interfaces.
 *
 * Provides type definitions and function prototypes used to link the
 * DHD OS, bus, and protocol modules.
 *
 * Copyright (C) 1999-2012, Broadcom Corporation
 * 
 *      Unless you and Broadcom execute a separate written software license
 * agreement governing use of this software, this software is licensed to you
 * under the terms of the GNU General Public License version 2 (the "GPL"),
 * available at http://www.broadcom.com/licenses/GPLv2.php, with the
 * following added to such license:
 * 
 *      As a special exception, the copyright holders of this software give you
 * permission to link this software with independent modules, and to copy and
 * distribute the resulting executable under terms of your choice, provided that
 * you also meet, for each linked independent module, the terms and conditions of
 * the license of that module.  An independent module is a module which is not
 * derived from this software.  The special exception does not apply to any
 * modifications of the software.
 * 
 *      Notwithstanding the above, under no circumstances may you combine this
 * software in any way with any other Broadcom software provided under a license
 * other than the GPL, without Broadcom's express prior written consent.
 *
 * $Id: dhd_bus.h 313456 2012-02-07 22:03:40Z $
 */

#ifndef _dhd_bus_h_
#define _dhd_bus_h_


extern int dhd_bus_register(void);
extern void dhd_bus_unregister(void);

extern bool dhd_bus_download_firmware(struct dhd_bus *bus, osl_t *osh,
	char *fw_path, char *nv_path);

extern void dhd_bus_stop(struct dhd_bus *bus, bool enforce_mutex);

extern int dhd_bus_init(dhd_pub_t *dhdp, bool enforce_mutex);

extern void dhd_bus_getidletime(dhd_pub_t *dhdp, int *idletime);

extern void dhd_bus_setidletime(dhd_pub_t *dhdp, int idle_time);

extern int dhd_bus_txdata(struct dhd_bus *bus, void *txp);

extern int dhd_bus_txctl(struct dhd_bus *bus, uchar *msg, uint msglen);
extern int dhd_bus_rxctl(struct dhd_bus *bus, uchar *msg, uint msglen);

extern bool dhd_bus_watchdog(dhd_pub_t *dhd);
extern void dhd_disable_intr(dhd_pub_t *dhd);

#if defined(DHD_DEBUG)
extern int dhd_bus_console_in(dhd_pub_t *dhd, uchar *msg, uint msglen);
#endif 

extern bool dhd_bus_dpc(struct dhd_bus *bus);
extern void dhd_bus_isr(bool * InterruptRecognized, bool * QueueMiniportHandleInterrupt, void *arg);


extern int dhd_bus_iovar_op(dhd_pub_t *dhdp, const char *name,
                            void *params, int plen, void *arg, int len, bool set);

extern void dhd_bus_dump(dhd_pub_t *dhdp, struct bcmstrbuf *strbuf);

extern void dhd_bus_clearcounts(dhd_pub_t *dhdp);

extern uint dhd_bus_chip(struct dhd_bus *bus);

extern void dhd_bus_set_nvram_params(struct dhd_bus * bus, const char *nvram_params);

extern void *dhd_bus_pub(struct dhd_bus *bus);
extern void *dhd_bus_txq(struct dhd_bus *bus);
extern uint dhd_bus_hdrlen(struct dhd_bus *bus);


#define DHD_SET_BUS_STATE_DOWN(_bus)  do { \
	(_bus)->dhd->busstate = DHD_BUS_DOWN; \
} while (0)

extern int dhd_bus_reg_sdio_notify(void* semaphore);
extern void dhd_bus_unreg_sdio_notify(void);

#endif 
