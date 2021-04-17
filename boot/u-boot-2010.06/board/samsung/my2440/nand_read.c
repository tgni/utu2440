#include <config.h>

#define BUSY 1
#define NF_BASE   0x4E000000  //Nand Flash���üĴ�������ַ

#define __REGb(x) (*(volatile unsigned char *)(x))
#define __REGi(x) (*(volatile unsigned int  *)(x))

#define NFCONF __REGi(NF_BASE + 0x0 )  //ͨ��ƫ�������ǵõ����üĴ�������ַ
#define NFCONT __REGi(NF_BASE + 0x4 )  //ͨ��ƫ�����õ����ƼĴ�������ַ
#define NFCMD  __REGb(NF_BASE + 0x8 )  //ͨ��ƫ�����õ�ָ��Ĵ�������ַ
#define NFADDR __REGb(NF_BASE + 0xC )  //ͨ��ƫ�����õ���ַ�Ĵ�������ַ
#define NFDATA __REGb(NF_BASE + 0x10)  //ͨ��ƫ�����õ����ݼĴ�������ַ
#define NFSTAT __REGb(NF_BASE + 0x20)  //ͨ��ƫ�����õ�״̬�Ĵ�������ַ

#define NAND_CHIP_ENABLE  (NFCONT &= ~(1<<1))  //NandƬѡʹ��
#define NAND_CHIP_DISABLE (NFCONT |= (1<<1))   //ȡ��NandƬѡ

#define NAND_CLEAR_RB     (NFSTAT |= (1<<2))
#define NAND_DETECT_RB    { while(! (NFSTAT&(1<<2)) );}
//#define NAND_CLEAR_RB     (NFSTAT |= BUSY)
//#define NAND_DETECT_RB    { while(!(NFSTAT & BUSY));}

//#define NAND_SECTOR_SIZE  2048
#define NAND_SECTOR_SIZE  512
#define NAND_BLOCK_MASK   (NAND_SECTOR_SIZE - 1)

#if 0
static void s3c2440_write_addr_lp(unsigned int addr)
{
	int i;
	volatile unsigned char *p = (volatile unsigned char *)&NFADDR;
	int col, page;

	col = addr & NAND_BLOCK_MASK;
	page = addr / NAND_SECTOR_SIZE;

	*p = col & 0xff;   /* Column Address A0~A7 */
	for(i=0; i<10; i++);  
	*p = (col >> 8) & 0x0f;  /* Column Address A8~A11 */
	for(i=0; i<10; i++);
	*p = page & 0xff;   /* Row Address A12~A19 */
	for(i=0; i<10; i++);
	*p = (page >> 8) & 0xff; /* Row Address A20~A27 */
	for(i=0; i<10; i++);                                                            
	*p = (page >> 16) & 0x01; /* Row Address A28~A29 */
	for(i=0; i<10; i++);                                                                                         

}
#endif

/* low level nand read function */
int nand_read_ll(unsigned char *buf, unsigned long start_addr, int size)
{
	int i, j;

	if ((start_addr & NAND_BLOCK_MASK) || (size & NAND_BLOCK_MASK)) {
		return -1; //��ַ�򳤶Ȳ�����
	}

	NAND_CHIP_ENABLE; //ѡ��NandƬѡ

	for (i = start_addr; i < (start_addr + size);) {
		//����READ0ָ��
		NAND_CLEAR_RB;
		NFCMD = 0;

		//s3c2440_write_addr_lp(i);
		//2k page
		//NFCMD = 0x30;
		
		//��Nand����Ѱַ
		NFADDR = i & 0xFF;
		NFADDR = (i >> 9) & 0xFF;
		NFADDR = (i >> 17) & 0xFF;
		NFADDR = (i >> 25) & 0xFF;

		NAND_DETECT_RB;

		for(j=0; j < NAND_SECTOR_SIZE; j++, i++) 
		{
			*buf = NFDATA;
			buf++;
		}
	}

	NAND_CHIP_DISABLE; //ȡ��Ƭѡ�ź�

	return 0;
}
