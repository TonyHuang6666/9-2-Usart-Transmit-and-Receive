#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;

int main(void)
{
	OLED_Init();
	OLED_ShowString(1, 1, "Hi!");
	Serial_Initilize();
	while(1)
	{
		if(Serial_GetRxFlag() == 1)
		{
			RxData = Serial_GetRxData();
			OLED_ShowHexNum(2, 1, RxData, 2);
		}
	}
}
