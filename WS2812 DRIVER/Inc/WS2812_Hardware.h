#ifndef INC_WS2812_HARDWARE_H_
#define INC_WS2812_HARDWARE_H_

#include "main.h"

#define  MAX_LED 14
#define USE_BRIGHTNESS 1 //set to 0 to disable brightness

extern TIM_HandleTypeDef htim1;
extern DMA_HandleTypeDef hdmaHandle ;
extern uint8_t datasentflag;


void WS2812_GPIO_Init(void);

void WS2812_TIM_Init(void);

void WS2812_DMA_Init(void);



#endif /* INC_WS2812_HARDWARE_H_ */
