#ifndef __LINUX_BRIDGE_EBT_802_3_H
#define __LINUX_BRIDGE_EBT_802_3_H

#include <linux/types.h>

#define EBT_802_3_SAP 0x01
#define EBT_802_3_TYPE 0x02

#define EBT_802_3_MATCH "802_3"

#define CHECK_TYPE 0xaa

#define IS_UI 0x03

#define EBT_802_3_MASK (EBT_802_3_SAP | EBT_802_3_TYPE | EBT_802_3)

struct hdr_ui {
	__u8 dsap;
	__u8 ssap;
	__u8 ctrl;
	__u8 orig[3];
	__be16 type;
};

struct hdr_ni {
	__u8 dsap;
	__u8 ssap;
	__be16 ctrl;
	__u8  orig[3];
	__be16 type;
};

struct ebt_802_3_hdr {
	__u8  daddr[6];
	__u8  saddr[6];
	__be16 len;
	union {
		struct hdr_ui ui;
		struct hdr_ni ni;
	} llc;
};

#ifdef __KERNEL__
#include <linux/skbuff.h>

static inline struct ebt_802_3_hdr *ebt_802_3_hdr(const struct sk_buff *skb)
{
	return (struct ebt_802_3_hdr *)skb_mac_header(skb);
}
#endif

struct ebt_802_3_info {
	__u8  sap;
	__be16 type;
	__u8  bitmask;
	__u8  invflags;
};

#endif