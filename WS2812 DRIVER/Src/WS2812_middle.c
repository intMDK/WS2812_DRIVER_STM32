#include "WS2812_middle.h"
#include "WS2812_Hardware.h"
#include "math.h"


 uint8_t LED_Data[MAX_LED][4];
 uint8_t LED_Mod[MAX_LED][4];
 uint16_t pwmData[(24*MAX_LED)+50];


void WS2812_Init(void)
{
	WS2812_GPIO_Init();
	WS2812_TIM_Init();
	WS2812_DMA_Init();
}

void WS2812_send(void)
{
	uint32_t indx=0;
	uint32_t color;


	for (int i= 0; i<MAX_LED; i++)
	{
#if USE_BRIGHTNESS
		color = ((LED_Mod[i][1]<<16) | (LED_Mod[i][2]<<8) | (LED_Mod[i][3]));
#else
		color = ((LED_Data[i][1]<<16) | (LED_Data[i][2]<<8) | (LED_Data[i][3]));
#endif

		for (int i=23; i>=0; i--)
		{
			if (color&(1<<i))
			{
				pwmData[indx] = 63;  // 2/3 of 90
			}

			else pwmData[indx] = 33;  // 1/3 of 90

			indx++;
		}

	}

	for (int i=0; i<50; i++)
	{
		pwmData[indx] = 0;
		indx++;
	}

	HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t *)pwmData, indx);
	while (!datasentflag){};
	datasentflag = 0;

}
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Stop_DMA(&htim1, TIM_CHANNEL_1);
	datasentflag=1;
}
void Set_Brightness(uint8_t brightness_0to45)
{
#if USE_BRIGHTNESS

	float angle=0;
	if (brightness_0to45 > 45) brightness_0to45 = 45;
	for (int i=0; i<MAX_LED; i++)
	{
		LED_Mod[i][0] = LED_Data[i][0];
		for (int j=1; j<4; j++)
		{
			 angle = 90-brightness_0to45;  // in degrees
			angle = angle*PI / 180;  // in rad
			LED_Mod[i][j] = (LED_Data[i][j])/(tan(angle));
		}
	}

#endif

}
void Set_LED (uint8_t LEDnum, uint8_t Red, uint8_t Green, uint8_t Blue)
{
	LED_Data[LEDnum][0] = LEDnum;
	LED_Data[LEDnum][1] = Green;
	LED_Data[LEDnum][2] = Red;
	LED_Data[LEDnum][3] = Blue;
}
