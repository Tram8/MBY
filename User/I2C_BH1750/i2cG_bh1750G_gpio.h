#ifndef __i2cG_GPIO_H
#define __i2cG_GPIO_H

#include "stm32f10x.h"

#define BH1750G_i2cG_WR	0		
#define BH1750G_i2cG_RD	1		


#define BH1750G_GPIO_PORT_i2cG	GPIOA			
#define BH1750G_RCC_i2cG_PORT 	RCC_APB2Periph_GPIOA		
#define BH1750G_i2cG_SCL_PIN		GPIO_Pin_11	
#define BH1750G_i2cG_SDA_PIN		GPIO_Pin_10



#if 0	
	#define BH1750G_i2cG_SCL_1()  GPIO_SetBits(BH1750G_GPIO_PORT_i2cG, BH1750G_i2cG_SCL_PIN)		
	#define BH1750G_i2cG_SCL_0()  GPIO_ResetBits(BH1750G_GPIO_PORT_i2cG, BH1750G_i2cG_SCL_PIN)		
	
	#define BH1750G_i2cG_SDA_1()  GPIO_SetBits(BH1750G_GPIO_PORT_i2cG, BH1750G_i2cG_SDA_PIN)		
	#define BH1750G_i2cG_SDA_0()  GPIO_ResetBits(BH1750G_GPIO_PORT_i2cG, BH1750G_i2cG_SDA_PIN)		
	
	#define BH1750G_i2cG_SDA_READ()  GPIO_ReadInputDataBit(BH1750G_GPIO_PORT_i2cG, BH1750G_i2cG_SDA_PIN)	
#else	
	#define BH1750G_i2cG_SCL_1()  BH1750G_GPIO_PORT_i2cG->BSRR = BH1750G_i2cG_SCL_PIN				
	#define BH1750G_i2cG_SCL_0()  BH1750G_GPIO_PORT_i2cG->BRR = BH1750G_i2cG_SCL_PIN				
	
	#define BH1750G_i2cG_SDA_1()  BH1750G_GPIO_PORT_i2cG->BSRR = BH1750G_i2cG_SDA_PIN				
	#define BH1750G_i2cG_SDA_0()  BH1750G_GPIO_PORT_i2cG->BRR = BH1750G_i2cG_SDA_PIN				
	
	#define BH1750G_i2cG_SDA_READ()  ((BH1750G_GPIO_PORT_i2cG->IDR & BH1750G_i2cG_SDA_PIN) != 0)	
#endif


void i2cG_Start(void);
void i2cG_Stop(void);
void i2cG_SendByte(uint8_t _ucByte);
uint8_t i2cG_ReadByte(void);
uint8_t i2cG_WaitAck(void);
void i2cG_Ack(void);
void i2cG_NAck(void);
uint8_t i2cG_CheckDevice(uint8_t _Address);


#endif

