#ifndef __E2213JS0C1_H
#define __E2213JS0C1_H

#include "main.h"

#define FIRMWARE_VERSION   ("2.0.0")

#define DISABLE 0
#define ENABLE  1

/* 是否有外部SPI flash硬件存在 */
#define EXTERNAL_SPI_FLASH_CONFIG       (ENABLE)

/*引脚定义*************************************************************************/
/* SPI号 */
#define E2213JS0C1_SPI					(SPI1)
/* CS */
#define E2213JS0C1_CS_ENABLE() \
	LL_GPIO_ResetOutputPin(DO_SCREEN_CS_GPIO_Port, DO_SCREEN_CS_Pin)
#define E2213JS0C1_CS_DISABLE() \
    LL_GPIO_SetOutputPin(DO_SCREEN_CS_GPIO_Port, DO_SCREEN_CS_Pin)
/* DC */
#define E2213JS0C1_DC_DATA() \
    LL_GPIO_SetOutputPin(DO_SCREEN_DC_GPIO_Port, DO_SCREEN_DC_Pin)
#define E2213JS0C1_DC_CMD() \
    LL_GPIO_ResetOutputPin(DO_SCREEN_DC_GPIO_Port, DO_SCREEN_DC_Pin)
/* RST */
#define E2213JS0C1_RST_ENABLE() \
    LL_GPIO_SetOutputPin(DO_SCREEN_RST_GPIO_Port, DO_SCREEN_RST_Pin)
#define E2213JS0C1_RST_DISABLE() \
    LL_GPIO_ResetOutputPin(DO_SCREEN_RST_GPIO_Port, DO_SCREEN_RST_Pin)
/* BUSY */
#define E2213JS0C1_BUSY_READ() \
    LL_GPIO_IsInputPinSet(DI_SCREEN_BUSY_GPIO_Port,DI_SCREEN_BUSY_Pin)
/*枚举*****************************************************************************/
/* 方向：水平/垂直 */
enum ENUM_ORIENTATION
{
    HORIZONTAL,
    VERTICAL
};
/* 填充：实心/空心 */
enum ENUM_FILL
{
    SOLID,
    HOLLOW
};
/*屏幕参数*************************************************************************/
//typedef struct
//{
//    uint8_t Orientation;    /* 显示方向 */
//	uint8_t Wide;           /* 宽度（pix） */
//	uint8_t High;           /* 高度（pix） */
//    uint8_t XPosMax;        /* X轴最大值 */
//    uint8_t YPosMax;        /* Y轴最大值 */
//} E2213JS0C1_InfoTypedef;
/* X轴坐标0~103；Y轴坐标0~211 */
#define E2213JS0C1_W 104
#define E2213JS0C1_H 212
#define E2213JS0C1_XPOS_MAX 103
#define E2213JS0C1_YPOS_MAX 211
#define E2213JS0C1_BUFFER_SIZE (E2213JS0C1_W * E2213JS0C1_H / 8)
#define E2213JS0C1_BUFFER_WIDTH_SIZE (E2213JS0C1_W / 8)
#define E2213JS0C1_BUFFER_HEIGHT_SIZE (E2213JS0C1_H)
#if EXTERNAL_SPI_FLASH_CONFIG == ENABLE
#define E2213JS0C1_FLASH_READ_BUFFER_SIZE (E2213JS0C1_H * 2)
#endif
/*颜色*****************************************************************************/
enum ENUM_COLOR 
{
    RED,
    WHITE,
    BLACK,
    GREY,
    DARKRED,
    LIGHTRED
};
/* 01红，00白，10黑 */
#define RED_BUFFER1             0X00
#define RED_BUFFER2             0XFF
#define WHITE_BUFFER1           0x00
#define WHITE_BUFFER2           0x00
#define BLACK_BUFFER1           0xFF
#define BLACK_BUFFER2           0x00
/* 红白相间=浅红色，红黑相间=深红色，黑白相间=灰色 */
#define GREY_BUFFER1_SINGLE     0xAA
#define GREY_BUFFER1_DOUBLE     0x55
#define GREY_BUFFER2            0x00
#define DARKRED_BUFFER1_SINGLE  0xAA
#define DARKRED_BUFFER1_DOUBLE  0x55
#define DARKRED_BUFFER2_SINGLE  0x55
#define DARKRED_BUFFER2_DOUBLE  0xAA
#define LIGHTRED_BUFFER1        0x00
#define LIGHTRED_BUFFER2_SINGLE 0xAA
#define LIGHTRED_BUFFER2_DOUBLE 0x55
/* RGB565 */
#define RGB565_RED              0xF800
#define RGB565_WHITE            0xFFFF
#define RGB565_BLACK            0x0000
/*字库*****************************************************************************/
#define FONT_1608		    (0)
#define FONT_1608_WIDTH		(8)
#define FONT_1608_HEIGHT	(16)

#if EXTERNAL_SPI_FLASH_CONFIG == ENABLE
/***************************** Flash中各资源的起始地址 *********************************/
enum ENUM_FLASH_FONT
{
    FONT_16,
};
#define ADDR_GBK_FONT_16_START  (0x00000000)
#define OFFSET_GBK_FONT_16      (32)
#define WIDTH_GBK_FONT_16		(16)
#define HEIGHT_GBK_FONT_16		(16)
#define ADDR_ASCII_FONT_16_START  (0x000BB080)
#define OFFSET_ASCII_FONT_16      (16)
#define WIDTH_ASCII_FONT_16		  (8)
#define HEIGHT_ASCII_FONT_16	  (16)

#define ADDR_BMP_START      (0x000BB670)
#define WIDTH_BMP		    (104)
#define HEIGHT_BMP		    (41)

#define ADDR_IMAGE_START    (0x000BB885)
#define WIDTH_IMAGE		    (104)
#define HEIGHT_IMAGE		(212)

#endif
/*指令*****************************************************************************/
#define SOFT_RESET_CMD          0x00
#define SOFT_RESET_DATA         0x0E
#define SET_TEMP_CMD            0xE5
#define SET_TEMP_25_DATA        0x19
#define ACTIVE_TEMP_CMD         0xE0
#define ACTIVE_TEMP_25_DATA     0x02
//#define PANEL_SET_CMD         0x00
//#define PANEL_SET_DATA_1      0xCF
//#define PANEL_SET_DATA_2      0x89
#define FIRST_FRAME_CMD         0x10
#define SECOND_FRAME_CMD        0x13
#define TURN_ON_DCDC_CMD        0x04
#define TURN_OFF_DCDC_CMD       0x02
#define DISPLAY_REFRESH_CMD     0x12
/*位操作***************************************************************************/
/* 指定的某一位数置1 */
#define SetBit(x, y)   (x |= (1<<y))
/* 指定的某一位数置0 */
#define ClearBit(x, y) (x &= ~(1<<y))
/* 指定的某一位数取反 */
#define ReverseBit(x,y) (x^=(1<<y))
/* 获取的某一位的值 */
#define GetBit(x, y)   ((x>>y) & 1)
/* 指定的某一位数置为指定的0或1 */
#define WriteBit(data, position, flag)   (flag ? SetBit(data, position) : ClearBit(data, position))
/*函数*******************************************************************************/
void E2213JS0C1_Init(uint8_t Orientation);
void E2213JS0C1_ClearFullScreen(enum ENUM_COLOR color);
void E2213JS0C1_RefreshScreen(void);
void E2213JS0C1_DrawPoint(uint8_t xPos, uint8_t yPos, enum ENUM_COLOR color);
void E2213JS0C1_DrawLine(uint8_t xStart, uint8_t yStart, uint8_t length, 
    enum ENUM_ORIENTATION orientation, enum ENUM_COLOR color);
void E2213JS0C1_DrawRectangle(uint8_t xStart, uint8_t yStart, uint8_t width, 
    uint8_t height, enum ENUM_FILL fill, enum ENUM_COLOR borderColor, 
    enum ENUM_COLOR fillColor);
uint8_t E2213JS0C1_ShowChar(uint8_t xStart, uint8_t yStart, char chr, 
    uint8_t font, enum ENUM_COLOR fontColor, enum ENUM_COLOR backgroundColor);
uint8_t E2213JS0C1_ShowCharStr(uint8_t xStart, uint8_t yStart, char* str, 
    uint8_t font, enum ENUM_COLOR fontColor, enum ENUM_COLOR backgroundColor);
void E2213JS0C1_DrawBmp(uint8_t xStart, uint8_t yStart, uint8_t bmpWidth, 
    uint8_t bmpHeight, enum ENUM_COLOR fontColor, enum ENUM_COLOR backgroundColor, 
    const unsigned char* pic);
void E2213JS0C1_DrawImage(uint8_t xStart, uint8_t yStart, uint8_t imageWidth, 
    uint8_t imageHeight, const unsigned char* pic);
#if EXTERNAL_SPI_FLASH_CONFIG == ENABLE
uint16_t E2213JS0C1_ShowGBKFontOrAsciiFromFlash(uint16_t startX, uint16_t startY, 
    enum ENUM_COLOR fontColor, enum ENUM_COLOR backgroundColor, enum ENUM_FLASH_FONT flashFont, uint8_t *str);
void E2213JS0C1_DrawImageFromFlash(uint8_t xStart, uint8_t yStart, uint8_t imageWidth, 
    uint8_t imageHeight, uint32_t readAddr);
void E2213JS0C1_DrawBmpFromFlash(uint8_t xStart, uint8_t yStart, uint8_t bmpWidth, 
    uint8_t bmpHeight, enum ENUM_COLOR fontColor, enum ENUM_COLOR backgroundColor, uint32_t readAddr);

#endif

#endif
