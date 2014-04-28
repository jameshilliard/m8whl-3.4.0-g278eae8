#ifndef _ADFS_FS_H
#define _ADFS_FS_H

#include <linux/types.h>
#include <linux/magic.h>

struct adfs_discrecord {
    __u8  log2secsize;
    __u8  secspertrack;
    __u8  heads;
    __u8  density;
    __u8  idlen;
    __u8  log2bpmb;
    __u8  skew;
    __u8  bootoption;
    __u8  lowsector;
    __u8  nzones;
    __le16 zone_spare;
    __le32 root;
    __le32 disc_size;
    __le16 disc_id;
    __u8  disc_name[10];
    __le32 disc_type;
    __le32 disc_size_high;
    __u8  log2sharesize:4;
    __u8  unused40:4;
    __u8  big_flag:1;
    __u8  unused41:1;
    __u8  nzones_high;
    __le32 format_version;
    __le32 root_size;
    __u8  unused52[60 - 52];
};

#define ADFS_DISCRECORD		(0xc00)
#define ADFS_DR_OFFSET		(0x1c0)
#define ADFS_DR_SIZE		 60
#define ADFS_DR_SIZE_BITS	(ADFS_DR_SIZE << 3)

#ifdef __KERNEL__
static inline int adfs_checkbblk(unsigned char *ptr)
{
	unsigned int result = 0;
	unsigned char *p = ptr + 511;

	do {
	        result = (result & 0xff) + (result >> 8);
        	result = result + *--p;
	} while (p != ptr);

	return (result & 0xff) != ptr[511];
}
#endif

#endif