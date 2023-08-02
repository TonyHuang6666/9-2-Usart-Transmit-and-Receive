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
		if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET)
		{
			RxData = USART_ReceiveData(USART1);
			//对USART_DR的读操作会自动清除RXNE标志位
			OLED_ShowHexNum(2, 1, RxData, 2);
		}
	}
}
