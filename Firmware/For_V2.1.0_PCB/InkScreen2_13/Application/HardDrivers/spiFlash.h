#ifndef __SPI_FLASH_H
#define __SPI_FLASH_H

/***************************** 头文件 ******************************************/
#include "main.h"	
/***************************** SPI序号、引脚 ***********************************/
/* SPI号 */
#define SPI_FLASH_SPI					(SPI2)
/* CS */
#define SPI_FLASH_CS_ENABLE() \
	LL_GPIO_ResetOutputPin(DO_FLASH_CS_GPIO_Port, DO_FLASH_CS_Pin)
#define SPI_FLASH_CS_DISABLE() \
    LL_GPIO_SetOutputPin(DO_FLASH_CS_GPIO_Port, DO_FLASH_CS_Pin)
/***************************** Flash中各资源的起始地址 *********************************/



/***************************** Flash的一些参数 *********************************/
/* W25QXX ID */
//#define SPI_FLASH_ID_W25Q16             (0xEF4015)
#define SPI_FLASH_ID_W25Q64             (0XEF4017)
//#define SPI_FLASH_ID_W25Q128            (0XEF4018)

/* 选择的Flash芯片型号 */
#define SPI_FLASH_ID					(SPI_FLASH_ID_W25Q64)

//#define SPI_FLASH_SECTOR_SIZE_BYTES		(4096u)	/* 每个扇区大小 */
//#define SPI_FLASH_SECTOR_COUNT			(2048u)	/* 总扇区数 */
//#define SPI_FLASH_PAGE_SIZE             (256u)	/* 每页大小 */

/********************************* 命令 ***************************************/
#define W25_CMD_WRITE_ENABLE		      	(0x06)
#define W25_CMD_WRITE_DISABLE		      	(0x04)
#define W25_CMD_READ_STATUS_REG		    	(0x05)
//#define W25_CMD_WRITE_STATUS_REG		    (0x01)
#define W25_CMD_READ_DATA			        (0x03)
//#define W25_CMD_FAST_READ_DATA		      	(0x0B)
//#define W25_CMD_FAST_READ_DUAL		      	(0x3B)
#define W25_CMD_PAGE_PROGRAM		      	(0x02)
//#define W25_CMD_BLOCK_ERASE			      	(0xD8)
#define W25_CMD_SECTOR_ERASE		      	(0x20)
//#define W25_CMD_CHIP_ERASE			      	(0xC7)
//#define W25_CMD_POWER_DOWN			      	(0xB9)
#define W25_CMD_RELEASE_POWER_DOWN	    	(0xAB)
#define W25_CMD_DEVICE_ID			    	(0xAB)
//#define W25_CMD_MANUFACT_DEVICE_ID   		(0x90)
#define W25_CMD_JEDEC_DEVICE_ID		    	(0x9F)

#define Dummy_Byte                		(0xFF)

// #define WIP_Flag                  		(0x01)/* WIP(busy)标志，FLASH内部正在写入 */

/*********************** 函数 *************************************************/
void SPI_FLASH_Init(void);
void SPI_FLASH_BufferRead(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead);
uint32_t SPI_FLASH_ReadID(void);

#endif
