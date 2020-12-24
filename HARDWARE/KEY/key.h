#ifndef	__KEY_H
#define __KEY_H
#include "sys.h"
#include "delay.h"

#define WK_UP_Pin GPIO_PIN_13
#define WK_UP_GPIO_Port GPIOC

#define KEY2_Pin GPIO_PIN_8
#define KEY2_GPIO_Port GPIOD

#define KEY1_Pin GPIO_PIN_9
#define KEY1_GPIO_Port GPIOD

#define KEY0_Pin GPIO_PIN_10
#define KEY0_GPIO_Port GPIOD

#define KEY0 			HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)
#define KEY1 			HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)
#define KEY2 			HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)
#define WK_UP 		HAL_GPIO_ReadPin(WK_UP_GPIO_Port,WK_UP_Pin)

void KEY_Init(void);

u8 KEY_Scan(u8 mode);

#endif


