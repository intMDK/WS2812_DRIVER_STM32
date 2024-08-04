#include "WS2812_Hardware.h"

TIM_HandleTypeDef htim1;
DMA_HandleTypeDef hdmaHandle ;


uint16_t TIM_Prescaler = 0;
uint16_t TIM_Period = 100;
uint8_t datasentflag;

void WS2812_GPIO_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef gpioInitStruct = {0};

	gpioInitStruct.Pin = GPIO_PIN_8;
	gpioInitStruct.Mode = GPIO_MODE_AF_PP;
	gpioInitStruct.Pull = GPIO_NOPULL;
	gpioInitStruct.Speed = GPIO_SPEED_LOW;
	gpioInitStruct.Alternate = GPIO_AF1_TIM1;
	HAL_GPIO_Init(GPIOA, &gpioInitStruct);
}
void WS2812_TIM_Init(void)
{
	__HAL_RCC_TIM1_CLK_ENABLE();
	// Initialize TIM1 instance and configure its parameters
	htim1.Instance = TIM1;
	htim1.Init.Prescaler = 0;
	htim1.Init.Period = TIM_Period-1;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.RepetitionCounter = 0;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	HAL_TIM_Base_Init(&htim1);

	// Configure the clock source for TIM1
	TIM_ClockConfigTypeDef timClockConfig = {0};
	timClockConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	HAL_TIM_ConfigClockSource(&htim1, &timClockConfig);
	HAL_TIM_PWM_Init(&htim1);

	// Configure Output Compare (OC) mode for TIM1 Channel 1
	TIM_OC_InitTypeDef ocConfig = {0};
	ocConfig.OCMode = TIM_OCMODE_PWM1;
	ocConfig.Pulse = 0;
	ocConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	ocConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	ocConfig.OCFastMode = TIM_OCFAST_DISABLE;
	ocConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	ocConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	HAL_TIM_PWM_ConfigChannel(&htim1, &ocConfig, TIM_CHANNEL_1);
}
void WS2812_DMA_Init(void)
{
	__HAL_RCC_DMA1_CLK_ENABLE();


	hdmaHandle.Instance = DMA1_Channel2;
	hdmaHandle.Init.Request = DMA_REQUEST_7;
	hdmaHandle.Init.Direction = DMA_MEMORY_TO_PERIPH;
	hdmaHandle.Init.PeriphInc = DMA_PINC_DISABLE;
	hdmaHandle.Init.MemInc = DMA_MINC_ENABLE;
	hdmaHandle.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
	hdmaHandle.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
	hdmaHandle.Init.Mode = DMA_NORMAL;
	hdmaHandle.Init.Priority = DMA_PRIORITY_LOW;
	HAL_DMA_Init(&hdmaHandle);
	__HAL_LINKDMA(&htim1,hdma[TIM_DMA_ID_CC1],hdmaHandle);


	HAL_NVIC_SetPriority(DMA1_Channel2_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA1_Channel2_IRQn);
}



