#include "main.h"
#include "rcc.h"
#include "gpio.h"
#include "WS2812_middle.h"
#include "WS2812_Hardware.h"




/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();


  /* Initialize all configured peripherals */
  GPIO_Init();
  WS2812_Init();

  Set_LED(0, 255, 0, 0);
  Set_LED(1,255, 0, 0);
  Set_LED(2, 255, 0, 0);
  Set_LED(3, 255, 0, 0);
  Set_LED(4, 255, 0, 0);
  Set_LED(5, 0, 255, 0);
  Set_LED(6,0, 255, 0);
  Set_LED(7,0, 255, 0);
  Set_LED(8,0, 255, 0);
  Set_LED(9,0, 255, 0);
  Set_LED(10,0, 0, 255);
  Set_LED(11, 0, 0, 255);
  Set_LED(12,0, 0, 255);
  Set_LED(13,0, 0, 255);




//  Set_Brightness(20);
//  WS2812_send();

  while (1)
  {
	  for (int i=0; i<46; i++)
		  {
		  	  Set_Brightness(i);
		  	WS2812_send();
		  	  HAL_Delay (50);
		  }

		  for (int i=45; i>=0; i--)
		  {
		  	  Set_Brightness(i);
		  	WS2812_send();
		  	  HAL_Delay (50);
		  }

  }

}




