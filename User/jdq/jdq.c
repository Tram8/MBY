#include "./jdq/jdq.h"
#include "stm32f10x.h"
 
void LED_init(void)
{
  GPIO_InitTypeDef     GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}          
 
void LED_on(void)
{
  GPIO_SetBits(GPIOA,GPIO_Pin_12);
}
 
void LED_off(void)
{ 
  GPIO_ResetBits(GPIOA,GPIO_Pin_12);
}
