#ifndef INC_WS2812_MIDDLE_H_
#define INC_WS2812_MIDDLE_H_

#include "main.h"
#include "math.h"

#define PI 3.14159265

void WS2812_Init(void);
void WS2812_send(void);
void Set_Brightness(uint8_t brightness);
void Set_LED (uint8_t LEDnum, uint8_t Red, uint8_t Green, uint8_t Blue);

#endif /* INC_WS2812_MIDDLE_H_ */
