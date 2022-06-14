#include "spiFlash.h"

/* 
注意！！！！这里把Flash睡眠、唤醒部分的代码注释掉了，
如果为了低功耗可以考虑把Flash睡眠、唤醒部分代码恢复。
但是！！！！睡眠唤醒部分代码没有经过调试，可能会有问题
*/

/* 
注意！因为这里的Flash只用来储存字库、图片、字符等数据，
所以没有擦除、写入的函数，防止误操作。
如有需要可以自行添加，这个网上一大堆，肯定能找到合适的。
*/

static uint8_t SPI_FLASH_SendReadByte(uint8_t byte);
//static void SPI_Flash_WakeUp(void);
//static void SPI_Flash_PowerDown(void);


/**
 * @brief : spiFlash初始化
 * @param : none
 * @retval: none
 */
void SPI_FLASH_Init(void)
{
	/* 开启SPI */
    LL_SPI_Enable(SPI_FLASH_SPI); 
    /* CS脚拉高 */
    SPI_FLASH_CS_DISABLE();
//	/* 先唤醒芯片，再让芯片休眠 */
//    SPI_Flash_WakeUp();
//    SPI_Flash_PowerDown();    
}

/**
 * @brief  读取FLASH数据
 * @param 	pBuffer，存储读出数据的指针
 * @param   ReadAddr，读取地址
 * @param   NumByteToRead，读取数据长度
 * @retval 无
 */
void SPI_FLASH_BufferRead(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
{
//	SPI_Flash_WakeUp();
	/* 选择FLASH: CS低电平 */
	SPI_FLASH_CS_ENABLE();

	/* 发送 读 指令 */
	SPI_FLASH_SendReadByte(W25_CMD_READ_DATA);

	/* 发送 读 地址高位 */
	SPI_FLASH_SendReadByte((ReadAddr & 0xFF0000) >> 16);
	SPI_FLASH_SendReadByte((ReadAddr& 0xFF00) >> 8);
	SPI_FLASH_SendReadByte(ReadAddr & 0xFF);

	/* 读取数据 */
	while (NumByteToRead--) /* while there is data to be read */
	{
		/* 读取一个字节*/
		*pBuffer = SPI_FLASH_SendReadByte(Dummy_Byte);
		/* 指向下一个字节缓冲区 */
		pBuffer++;
	}

	/* 停止信号 FLASH: CS 高电平 */
	SPI_FLASH_CS_DISABLE();

//	SPI_Flash_PowerDown();
}

/**
 * @brief  读取FLASH ID
 * @param  无
 * @retval FLASH ID
 */
uint32_t SPI_FLASH_ReadID(void)
{
	uint32_t Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;

//	SPI_Flash_WakeUp();
	/* 开始通讯：CS低电平 */
	SPI_FLASH_CS_ENABLE();

	/* 发送JEDEC指令，读取ID */
	SPI_FLASH_SendReadByte(W25_CMD_JEDEC_DEVICE_ID);
	/* 读取一个字节数据 */
	Temp0 = SPI_FLASH_SendReadByte(Dummy_Byte);
	Temp1 = SPI_FLASH_SendReadByte(Dummy_Byte);
	Temp2 = SPI_FLASH_SendReadByte(Dummy_Byte);

	/* 停止通讯：CS高电平 */
	SPI_FLASH_CS_DISABLE();

	/*把数据组合起来，作为函数的返回值*/
	Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;

//	SPI_Flash_PowerDown();
	return Temp;
}

/**
 * @brief  使用SPI发送一个字节的数据
 * @param  byte：要发送的数据
 * @retval 返回接收到的数据
 */
static uint8_t SPI_FLASH_SendReadByte(uint8_t byte)
{
    while (!LL_SPI_IsActiveFlag_TXE(SPI_FLASH_SPI));
	LL_SPI_TransmitData8(SPI_FLASH_SPI, byte);

	while (!LL_SPI_IsActiveFlag_RXNE(SPI_FLASH_SPI));
	return LL_SPI_ReceiveData8(SPI_FLASH_SPI);
}

///**
// * @brief  唤醒flash
// * @param  none
// * @retval none
// */
//static void SPI_Flash_WakeUp(void)
//{
//	/*选择 FLASH: CS 低 */
//	SPI_FLASH_CS_ENABLE();
//	/* 发送 上电 命令 */
//	SPI_FLASH_SendReadByte(W25_CMD_RELEASE_POWER_DOWN);
//	/* 停止信号 FLASH: CS 高 */
//	SPI_FLASH_CS_DISABLE();
//	/* 唤醒后需要等待tRES1（3us）才能正常工作 */
//    __NOP();
//    __NOP();
//    __NOP();
//}

///**
// * @brief  进入掉电模式（睡眠）
// * @param  none
// * @retval none
// */
//static void SPI_Flash_PowerDown(void)
//{
//	/* 通讯开始：CS低 */
//	SPI_FLASH_CS_ENABLE();
//	/* 发送 掉电 命令 */
//	SPI_FLASH_SendReadByte(W25_CMD_POWER_DOWN);
//	/*通讯结束：CS高 */
//	SPI_FLASH_CS_DISABLE();
//}
