#ifndef __BEEP_H
#define __BEEP_H
#include "sys.h"

#define BEEP(n)						(n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET))
#define BEEP_toggle				HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_2)

void BEEP_Init(void);


#endif


