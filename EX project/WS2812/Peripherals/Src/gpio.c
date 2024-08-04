#include "gpio.h"

void GPIO_Init(void)
{

	GPIO_InitTypeDef gpioInitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	gpioInitStruct.Pin = GPIO_PIN_9;
	gpioInitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	gpioInitStruct.Pull = GPIO_NOPULL;
	gpioInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpioInitStruct);
}
