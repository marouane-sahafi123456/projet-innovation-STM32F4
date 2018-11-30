
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
DAC_HandleTypeDef hdac;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DAC_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	
	#define DACBUFSIZE 360
	
	/* First input signal of sensors */

const uint16_t dacbuf1[DACBUFSIZE] = {4075,4070,4064,4057,4050,4042,4034,4025,4015,4005,3994,3983,3971,3959,3946,3932,3918,3903,3887,3871,
																				3855,3838,3820,3802,3783,3764,3744,3724,3703,3682,3660,3638,3615,3592,3568,3544,3520,3495,3469,3443,
	   																		3417,3390,3363,3335,3307,3279,3250,3221,3192,3162,3132,3101,3070,3039,3008,2976,2944,2912,2879,2847,
																				2813,2780,2747,2713,2679,2645,2611,2576,2542,2507,2472,2437,2402,2367,2331,2296,2260,2225,2189,2154,
																				2118,2082,2046,2011,1975,1939,1904,1868,1832,1797,1761,1726,1691,1656,1621,1586,1551,1517,1482,1448,
																				1414,1380,1346,1313,1279,1246,1214,1181,1149,1117,1085,1054,1023,992,962,931,902,872,843,814,786,758,
																				731,703,677,650,624,599,574,549,525,502,478,456,433,412,390,370,349,330,311,292,274,256,239,223,207,
																				191,177,162,149,136,123,111,100,89,79,69,61,52,45,37,31,25,20,15,11,8,5,3,1,0,0,0,1,3,5,8,11,15,20,25,
																				31,38,45,53,61,70,80,90,101,112,124,136,149,163,177,192,208,224,240,257,275,293,312,331,351,371,392,
																				413,435,457,480,503,527,551,575,600,626,652,678,705,732,760,788,816,845,874,903,933,963,994,1025,1056,
																				1087,1119,1151,1183,1216,1248,1282,1315,1348,1382,1416,1450,1484,1519,1553,1588,1623,1658,1693,
																				1728,1764,1799,1835,1870,1906,1941,1977,2013,2049,2084,2120,2156,2191,2227,2263,2298,2334,2369,2404,
																				2439,2474,2509,2544,2578,2613,2647,2681,2715,2749,2782,2816,2849,2881,2914,2946,2978,3010,3041,3072,
																				3103,3133,3164,3193,3223,3252,3281,3309,3337,3364,3392,3418,3445,3471,3496,3521,3546,3570,3593,3617,
																				3639,3662,3683,3705,3725,3746,3765,3784,3803,3821,3839,3856,3872,3888,3904,3918,3933,3946,3959,3972,
																				3984,3995,4006,4016,4026,4034,4043,4050,4058,4064,4070,4075,4080,4084,4087,4090,4092,4094,4095,4095,
																				4095,4094,4092,4090,4087,4084,4080}; 

	/* Second input signal of sensors  */
const uint16_t dacbuf2[DACBUFSIZE] = {3073,3042,3011,2979,2947,2915,2882,2849,2816,2783,2750,2716,2682,2648,2614,2580,2545,2510,2475,2440,
																				2405,2370,2335,2299,2264,2228,2192,2157,2121,2085,2050,2014,1978,1942,1907,1871,1836,1800,1765,1729,
																				1694,1659,1624,1589,1554,1520,1485,1451,1417,1383,1349,1316,1282,1249,1217,1184,1152,1120,1088,1057,
																				1026,995,964,934,904,875,846,817,789,761,733,706,679,653,627,601,576,552,527,504,480,458,435,414,392,
																				372,351,331,312,294,275,258,241,224,208,193,178,164,150,137,124,112,101,90,80,70,61,53,45,38,31,26,20,
																				16,11,8,5,3,1,0,0,0,1,3,5,8,11,15,20,25,31,37,44,52,60,69,79,89,100,111,123,135,148,162,176,191,206,222,
																				239,256,273,291,310,329,349,369,390,411,433,455,478,501,524,549,573,598,624,650,676,703,730,757,785,814,
																				842,871,901,931,961,991,1022,1053,1084,1116,1148,1180,1213,1246,1279,1312,1345,1379,1413,1447,1481,1515,
																				1550,1585,1620,1655,1690,1725,1760,1796,1831,1867,1903,1938,1974,2010,2045,2081,2117,2153,2188,2224,2259,
																				2295,2330,2366,2401,2436,2471,2506,2541,2575,2610,2644,2678,2712,2746,2779,2813,2846,2878,2911,2943,2975,
																				3007,3038,3069,3100,3131,3161,3191,3220,3249,3278,3306,3334,3362,3389,3416,3442,3468,3494,3519,3543,3568,
																				3591,3615,3637,3660,3681,3703,3723,3744,3764,3783,3801,3820,3837,3854,3871,3887,3902,3917,3931,3945,3958,
																				3971,3983,3994,4005,4015,4025,4034,4042,4050,4057,4064,4069,4075,4079,4084,4087,4090,4092,4094,4095,4095,
																				4095,4094,4092,4090,4087,4084,4080,4075,4070,4064,4058,4051,4043,4035,4026,4016,4006,3995,3984,3972,3960,
																				3947,3933,3919,3904,3889,3873,3856,3839,3822,3804,3785,3766,3746,3726,3705,3684,3662,3640,3617,3594,3571,
																				3546,3522,3497,3471,3445,3419,3392,3365,3338,3310,3281,3253,3224,3194,3164,3134,3104};
																				
																				
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

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
  MX_DAC_Init();
  /* USER CODE BEGIN 2 */

	HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
	

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
				
for(int i=0; i<360; i++) /* a loop for sweeping input signal data */
        {
					/* This part is about the switch use */
					
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET); /* setting up the first GPIO_PIN_0 */
					uint16_t b = HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_0);  /* Reading the state of the GPIO_PIN_0*/
          if (b == 1){                                      /* if the GPIO_PIN_0 is in the high mode*/
							HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1,DAC_ALIGN_12B_R,dacbuf1[i]);/* using DAC to convert  input signal from digital to analog mode*/
							DAC->SWTRIGR|=DAC_SWTRIGR_SWTRIG1;
					}
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET); /* Resetting up the first GPIO_PIN_0 */

					
					/* Now we will make a test on the other GPIO */
					
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);/* setting up the first GPIO_PIN_1 */
					uint16_t c = HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_1); /* Reading the state of the GPIO_PIN_1*/
          if (c == 1){                                      /* if the GPIO_PIN_1 is in the high mode*/
							HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1,DAC_ALIGN_12B_R,dacbuf2[i]); /* using DAC to convert input signal from digital to analog mode*/
							DAC->SWTRIGR|=DAC_SWTRIGR_SWTRIG1;
					}
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);/* Resetting up the first GPIO_PIN_1 */
					
            
						
						
  }
		
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

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* DAC init function */
static void MX_DAC_Init(void)
{

  DAC_ChannelConfTypeDef sConfig;

    /**DAC Initialization 
    */
  hdac.Instance = DAC;
  if (HAL_DAC_Init(&hdac) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**DAC channel OUT1 config 
    */
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC0 PC1 PC2 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
