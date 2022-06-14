/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

#include "stm32f1xx_ll_spi.h"
#include "stm32f1xx_ll_system.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_exti.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_cortex.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_pwr.h"
#include "stm32f1xx_ll_dma.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DI_SCREEN_BUSY_Pin LL_GPIO_PIN_1
#define DI_SCREEN_BUSY_GPIO_Port GPIOA
#define DO_SCREEN_DC_Pin LL_GPIO_PIN_2
#define DO_SCREEN_DC_GPIO_Port GPIOA
#define DO_SCREEN_RST_Pin LL_GPIO_PIN_3
#define DO_SCREEN_RST_GPIO_Port GPIOA
#define DO_SCREEN_CS_Pin LL_GPIO_PIN_4
#define DO_SCREEN_CS_GPIO_Port GPIOA
#define DO_SCREEN_CLK_Pin LL_GPIO_PIN_5
#define DO_SCREEN_CLK_GPIO_Port GPIOA
#define MO_SCREEN_MOSI_Pin LL_GPIO_PIN_7
#define MO_SCREEN_MOSI_GPIO_Port GPIOA
#define DO_FLASH_CS_Pin LL_GPIO_PIN_12
#define DO_FLASH_CS_GPIO_Port GPIOB
#define DO_FLASH_CLK_Pin LL_GPIO_PIN_13
#define DO_FLASH_CLK_GPIO_Port GPIOB
#define MO_FLASH_MISO_Pin LL_GPIO_PIN_14
#define MO_FLASH_MISO_GPIO_Port GPIOB
#define MO_FLASH_MOSI_Pin LL_GPIO_PIN_15
#define MO_FLASH_MOSI_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
