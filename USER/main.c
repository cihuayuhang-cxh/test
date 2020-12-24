#include "sys.h"
#include "delay.h"
#include "usart.h"

#include "led.h"
#include "beep.h"
#include "key.h"

#define RGB_LED_TEST
//#define BEEP_TEST
//#define KEY_TEST

#ifdef RGB_LED_TEST

int main(void)
{
	/****************片内外设初始化*********************/
	HAL_Init();											//初始化HAL库
	SystemClock_Config();						//初始化系统时钟为80M
	delay_init(80);									//初始化延时函数
	uart_init(115200);							//初始化串口
	
	/****************片外外设初始化*********************/
	LED_Init();											//初始化RGB_LED
	
	while(1)
	{
		LED_R(0);
		delay_ms(500);
		LED_R(1);
		delay_ms(500);
		LED_B(0);
		delay_ms(500);
		LED_B(1);
		delay_ms(500);
		LED_G(0);
		delay_ms(500);
		LED_G(1);
		delay_ms(500);
	}
}
#endif



#ifdef BEEP_TEST
int main(void)
{
	/****************片内外设初始化*********************/
	HAL_Init();											//初始化HAL库
	SystemClock_Config();						//初始化系统时钟为80M
	delay_init(80);									//初始化延时函数
	uart_init(115200);							//初始化串口
	
	/****************片外外设初始化*********************/
	BEEP_Init();											//初始化RGB_LED
	
	while(1)
	{
		BEEP(0);
		delay_ms(500);
		BEEP(1);
		delay_ms(500);
	}
}
#endif

#ifdef KEY_TEST
int main(void)
{
	/****************变量定义***************************/
	u8 Key_state=0;
	
	/****************片内外设初始化*********************/
	HAL_Init();											//初始化HAL库
	SystemClock_Config();						//初始化系统时钟为80M
	delay_init(80);									//初始化延时函数
	uart_init(115200);							//初始化串口
	
	/****************片外外设初始化*********************/
	LED_Init();
	BEEP_Init();											//初始化RGB_LED
	KEY_Init();
	
	while(1)
	{
		Key_state=KEY_Scan(0);
		switch (Key_state)
		{
			case 0:	break;
			case 1:
				LED_R_toggle;
				break;
			case(2):
				LED_G_toggle;
				break;
			case(3):
				LED_B_toggle;
				break;
			case(4):
				BEEP_toggle;
				break;
			default : break;
			
		}
	}
}
#endif



