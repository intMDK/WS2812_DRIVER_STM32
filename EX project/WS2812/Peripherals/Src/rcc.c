#include "rcc.h"


void SystemClock_Config(void)
{
	RCC_OscInitTypeDef rccOscInitStruct ={0};
	RCC_ClkInitTypeDef rccClkInitStruct ={0};

	 HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) ;


	//OSC configuration
	rccOscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	rccOscInitStruct.HSIState = RCC_HSI_ON;
	rccOscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	rccOscInitStruct.PLL.PLLState = RCC_PLL_ON;
	rccOscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	rccOscInitStruct.PLL.PLLM = 1;
	rccOscInitStruct.PLL.PLLN = 10;
	rccOscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
	rccOscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
	rccOscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;

	HAL_RCC_OscConfig(&rccOscInitStruct);

	//CLK configuration
	rccClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 |
			RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_SYSCLK;
	rccClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	rccClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	rccClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	rccClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	HAL_RCC_ClockConfig(&rccClkInitStruct, FLASH_LATENCY_4);

}


