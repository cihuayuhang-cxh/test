#include "key.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin : WK_UP_Pin */
  GPIO_InitStruct.Pin = WK_UP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(WK_UP_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : KEY2_Pin KEY1_Pin KEY0_Pin */
  GPIO_InitStruct.Pin = KEY2_Pin|KEY1_Pin|KEY0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}


u8 KEY_Scan(u8 mode)
{
	static u8 KEY_State=0;					//KEY_State等于0时表示没有按键处于按下状态
	
	if(mode)KEY_State=0;					//mode等于1时表示可连续按下
	
	if(KEY_State==0&&(KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
	{
		KEY_State=1;
		delay_ms(15);
		if(KEY0==0)return 1;
		else if (KEY1==0)return 2;
		else if (KEY2==0)return 3;
		else if (WK_UP==1)return 4;
		else return 0;
	}
	else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)KEY_State=0;
	return 0;
}


