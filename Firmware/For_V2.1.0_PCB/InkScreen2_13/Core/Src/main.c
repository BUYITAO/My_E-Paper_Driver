/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "E2213JS0C1.h"
#include "spiFlash.h"
#include "image.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  /* 初始化墨水屏 */
  E2213JS0C1_Init(0);
//  /* 显示图片测试 */
//  E2213JS0C1_DrawImage(0,0,104,212,gImage_1);  
//  E2213JS0C1_FlashScreen();
//  HAL_Delay(3000);
//  /* 显示点、线、矩形、ASCII字符、bpm图片测试 */
//  E2213JS0C1_ClearFullScreen(WHITE);
//  E2213JS0C1_DrawPoint(0,0,RED);
//  E2213JS0C1_DrawLine(0,2,10,HORIZONTAL,BLACK);
//  E2213JS0C1_DrawLine(0,4,10,VERTICAL,BLACK);    
//  E2213JS0C1_DrawRectangle(0,16,10,10,SOLID,BLACK,RED);   
//  E2213JS0C1_DrawRectangle(20,16,10,10,HOLLOW,BLACK,RED);          
//  E2213JS0C1_ShowCharStr(0,30,"FONT TEST",FONT_1608,BLACK,WHITE);
//  E2213JS0C1_DrawBmp(0,50,104,41,BLACK,WHITE,BmpImage);
//  E2213JS0C1_ShowCharStr(0,100,"UID:112222162",FONT_1608,BLACK,WHITE);  
//  E2213JS0C1_ShowCharStr(20,116,"Designed",FONT_1608,BLACK,WHITE);
//  E2213JS0C1_ShowCharStr(44,132,"By",FONT_1608,BLACK,WHITE);
//  E2213JS0C1_ShowCharStr(40,148,"BYT",FONT_1608,BLACK,WHITE);
//  E2213JS0C1_FlashScreen();  
#if EXTERNAL_SPI_FLASH_CONFIG == ENABLE
  /* 初始化Flash */
  SPI_FLASH_Init();
  /* 读取Flash ID，用于确认Flash是否存在，如果检测不到Flash就会卡死不显示 */
  uint32_t id = SPI_FLASH_ReadID();
  /* Flash型号正确 */
  if (id == SPI_FLASH_ID)
  {
      /* Flash中的中文显示测试 */
      E2213JS0C1_ClearFullScreen(WHITE);      
      uint8_t chinese[5] = {0xB2, 0xE2, 0xCA, 0xD4, 0x00};
      E2213JS0C1_ShowGBKFontOrAsciiFromFlash(0, 100, BLACK, WHITE, FONT_16, chinese);  
      E2213JS0C1_FlashScreen();
      /* Flash中的ASCII字符显示测试 */
      
      /* Flash中的bmp图片显示测试 */
      
      /* Flash中的三色图显示测试 */
      
      
      
  }
  /* Flash型号不对 */
  else
  {
      E2213JS0C1_ClearFullScreen(WHITE);
      E2213JS0C1_ShowCharStr(0,80,"Incorrect ",FONT_1608,BLACK,WHITE);  
      E2213JS0C1_ShowCharStr(0,100,"Flash",FONT_1608,BLACK,WHITE); 
      E2213JS0C1_ShowCharStr(0,120,"model",FONT_1608,BLACK,WHITE);       
      E2213JS0C1_FlashScreen();
  }
#endif
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
