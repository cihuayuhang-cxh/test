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
	/****************Ƭ�������ʼ��*********************/
	HAL_Init();											//��ʼ��HAL��
	SystemClock_Config();						//��ʼ��ϵͳʱ��Ϊ80M
	delay_init(80);									//��ʼ����ʱ����
	uart_init(115200);							//��ʼ������
	
	/****************Ƭ�������ʼ��*********************/
	LED_Init();											//��ʼ��RGB_LED
	
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
	/****************Ƭ�������ʼ��*********************/
	HAL_Init();											//��ʼ��HAL��
	SystemClock_Config();						//��ʼ��ϵͳʱ��Ϊ80M
	delay_init(80);									//��ʼ����ʱ����
	uart_init(115200);							//��ʼ������
	
	/****************Ƭ�������ʼ��*********************/
	BEEP_Init();											//��ʼ��RGB_LED
	
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
	/****************��������***************************/
	u8 Key_state=0;
	
	/****************Ƭ�������ʼ��*********************/
	HAL_Init();											//��ʼ��HAL��
	SystemClock_Config();						//��ʼ��ϵͳʱ��Ϊ80M
	delay_init(80);									//��ʼ����ʱ����
	uart_init(115200);							//��ʼ������
	
	/****************Ƭ�������ʼ��*********************/
	LED_Init();
	BEEP_Init();											//��ʼ��RGB_LED
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



