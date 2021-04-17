/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <garyj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * Configuation settings for the SAMSUNG SMDK2410 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM920T	1	/* This is an ARM920T Core	*/
#define CONFIG_S3C24X0	1	/* in a SAMSUNG S3C24x0-type SoC	*/
#define CONFIG_S3C2410	1	/* specifically a SAMSUNG S3C2410 SoC	*/
#define CONFIG_SMDK2410	1	/* on a SAMSUNG SMDK2410 Board  */
#define CONFIG_S3C2440        1    /* in a SAMSUNG S3C2440 SoC    */

/* input clock of PLL */
#define CONFIG_SYS_CLK_FREQ	12000000 /* the SMDK2410 has 12MHz input clock */

#define USE_920T_MMU		1
#undef CONFIG_USE_IRQ			/* we don't need IRQ/FIQ stuff */

/*
 * Size of malloc() pool
 */
//env size is 128k, malloc size is 128k, then malloc len is 256k

#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 128*1024)
#define CONFIG_SYS_GBL_DATA_SIZE	128	/* size in bytes reserved for initial data */

/*
 * Hardware drivers
 */
#if 0
#define CONFIG_NET_MULTI
#define CONFIG_CS8900		/* we have a CS8900 on-board */
#define CONFIG_CS8900_BASE	0x19000300
#define CONFIG_CS8900_BUS16	/* the Linux driver does accesses as shorts */
#endif
#define CONFIG_DRIVER_DM9000    1  
#define CONFIG_NET_MULTI        1
//#define CONFIG_DM9000_BASE      0x20000300  //����Ƭѡ��ַ
#define CONFIG_DM9000_BASE      0x18000300  //����Ƭѡ��ַ
#define DM9000_IO               CONFIG_DM9000_BASE
#define DM9000_DATA             (CONFIG_DM9000_BASE + 4)   //�������ݵ�ַ

#define CONFIG_DM9000_USE_16BIT 1
#define CONFIG_DM9000_NO_SROM   1
//#define CONFIG_DM9000_DEBUG

#define CONFIG_CMD_PING



/*
 * select serial console configuration
 */
#define CONFIG_S3C24X0_SERIAL
#define CONFIG_SERIAL1          1	/* we use SERIAL 1 on SMDK2410 */

/************************************************************
 * RTC
 ************************************************************/
#define	CONFIG_RTC_S3C24X0	1

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE		115200


/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME


/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

#define CONFIG_CMD_CACHE
#define CONFIG_CMD_DATE
#define CONFIG_CMD_ELF


#define CONFIG_BOOTDELAY	3
/*#define CONFIG_BOOTARGS	"root=ramfs devfs=mount console=ttySA0,9600" */
#define CONFIG_ETHADDR		08:00:3e:26:0a:5b 
#define CONFIG_NETMASK          255.255.255.0
#define CONFIG_IPADDR		192.168.2.105
#define CONFIG_SERVERIP		192.168.2.15
/*#define CONFIG_BOOTFILE	"elinos-lart" */
/*#define CONFIG_BOOTCOMMAND	"tftp; bootm" */

#if defined(CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200		/* speed to run kgdb serial port */
/* what's this ? it's not used anywhere */
#define CONFIG_KGDB_SER_INDEX	1		/* which serial port to use */
#endif

/*
 * Miscellaneous configurable options
 */
#define	CONFIG_SYS_LONGHELP				/* undef to save memory		*/
#define	CONFIG_SYS_PROMPT		"u-boot2010.06@Daniel # "	/* Monitor Command Prompt	*/
#define	CONFIG_SYS_CBSIZE		256		/* Console I/O Buffer Size	*/
#define	CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16) /* Print Buffer Size */
#define	CONFIG_SYS_MAXARGS		16		/* max number of command args	*/
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size	*/

#define CONFIG_SYS_MEMTEST_START	0x30000000	/* memtest works on	*/
#define CONFIG_SYS_MEMTEST_END		0x33F00000	/* 63 MB in DRAM	*/

#define	CONFIG_SYS_LOAD_ADDR		0x33000000	/* default load address	*/

#define	CONFIG_SYS_HZ			1000

/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4*1024)	/* FIQ stack */
#endif

/*-----------------------------------------------------------------------

* Physical Memory Map

*/

#define CONFIG_NR_DRAM_BANKS     1            /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1          0x30000000        /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE     0x04000000        /* 64 MB */
#define PHYS_FLASH_1         0x00000000          /* Flash Bank #1 */
#define CONFIG_SYS_FLASH_BASE       PHYS_FLASH_1
#define CONFIG_SYS_MONITOR_BASE    TEXT_BASE  
#define FLASH_BASE0_PRELIM           PHYS_FLASH_1

//#define CONFIG_SYS_NO_FLASH	1
/*------------------------------------------------------------

* nand FLASH and environment organization

*/

#define CONFIG_SYS_FLASH_PROTECTION    1
#define CONFIG_SYS_MAX_FLASH_BANKS     1       /*max number of memory banks*/
#define CONFIG_SYS_FLASH_SIZE     0x00400000     /*4 MB*/
#define CONFIG_SYS_MAX_FLASH_SECT     32     /*max number of sectors on one chip*/
/*timeout values are in ticks*/
#define CONFIG_SYS_FLASH_ERASE_TOUT     (2*CONFIG_SYS_HZ) 
/*Timeout for Flash Erase*/
#define CONFIG_SYS_FLASH_WRITE_TOUT     (2*CONFIG_SYS_HZ) 
/*Timeout for Flash Write*/

/*
 * Nand flash register and envionment variables 
 */

#define CONFIG_CMD_NAND
#define CONFIG_NAND_S3C2440 1
#define CONFIG_CMDLINE_EDITING
#ifdef CONFIG_CMDLINE_EDITING
    # undef CONFIG_AUTO_COMPLETE
#else
    #define CONFIG_AUTO_COMPLETE
#endif
#if defined(CONFIG_CMD_NAND)
#define CONFIG_SYS_NAND_BASE 0x4E000000 //Nand���üĴ�������ַ
#define CONFIG_SYS_MAX_NAND_DEVICE 1 
#define CONFIG_MTD_NAND_VERIFY_WRITE 1 
//#define NAND_SAMSUNG_LP_OPTIONS 1       //ע�⣺����������64M��Nand Flash�����Բ��ã������128M�Ĵ��Nand Flash���������
#endif

#define CONFIG_ENV_IS_IN_NAND  1
#define CONFIG_ENV_OFFSET      0x40000 //�������������浽nand�е�0x40000λ��
#define CONFIG_ENV_SIZE        0x20000 /* Total Size of Environment Sector */

//#define CONFIG_SKIP_LOWLEVEL_INIT   1
#define CONFIG_S3C2440_NAND_BOOT    1
#define NAND_CTL_BASE  0x4E000000 

#define STACK_BASE  0x33F00000     
#define STACK_SIZE  0x8000         

#define oNFCONF  0x00 
#define oNFCONT  0x04 

#define oNFADDR  0x0c //0x4E00000c
#define oNFDATA  0x10 //0x4E000010
#define oNFCMD   0x08 //0x4E000008
#define oNFSTAT  0x20 //0x4E000020

#define oNFECC   0x2c //0x4E00002c
/*
��yaffs2��֧��
*/


#define CONFIG_MTD_NAND_YAFFS2   1 //����һ�������Yaffs2֧�ֵĺ�
//����Nand FlashĬ�Ϸ�����ע��˴��ķ���Ҫ������ں��еķ�������һ��
#define MTDIDS_DEFAULT "nand0=nandflash0"
#define MTDPARTS_DEFAULT "mtdparts=nandflash0:256k(bootloader)," \
                     "128k(params)," \
                     "10m(kernel)," \
                     "-(root)"
 /*
support nfs
 */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG


#endif	/* __CONFIG_H */
