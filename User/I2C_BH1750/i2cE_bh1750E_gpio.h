#ifndef __i2cE_GPIO_H
#define __i2cE_GPIO_H

#include "stm32f10x.h"

#define BH1750E_i2cE_WR	0		
#define BH1750E_i2cE_RD	1		


#define BH1750E_GPIO_PORT_i2cE	GPIOA			
#define BH1750E_RCC_i2cE_PORT 	RCC_APB2Periph_GPIOA		
#define BH1750E_i2cE_SCL_PIN		GPIO_Pin_9	
#define BH1750E_i2cE_SDA_PIN		GPIO_Pin_8



#if 0	
	#define BH1750E_i2cE_SCL_1()  GPIO_SetBits(BH1750E_GPIO_PORT_i2cE, BH1750E_i2cE_SCL_PIN)		
	#define BH1750E_i2cE_SCL_0()  GPIO_ResetBits(BH1750E_GPIO_PORT_i2cE, BH1750E_i2cE_SCL_PIN)		
	
	#define BH1750E_i2cE_SDA_1()  GPIO_SetBits(BH1750E_GPIO_PORT_i2cE, BH1750E_i2cE_SDA_PIN)		
	#define BH1750E_i2cE_SDA_0()  GPIO_ResetBits(BH1750E_GPIO_PORT_i2cE, BH1750E_i2cE_SDA_PIN)		
	
	#define BH1750E_i2cE_SDA_READ()  GPIO_ReadInputDataBit(BH1750E_GPIO_PORT_i2cE, BH1750E_i2cE_SDA_PIN)	
#else	
	#define BH1750E_i2cE_SCL_1()  BH1750E_GPIO_PORT_i2cE->BSRR = BH1750E_i2cE_SCL_PIN				
	#define BH1750E_i2cE_SCL_0()  BH1750E_GPIO_PORT_i2cE->BRR = BH1750E_i2cE_SCL_PIN				
	
	#define BH1750E_i2cE_SDA_1()  BH1750E_GPIO_PORT_i2cE->BSRR = BH1750E_i2cE_SDA_PIN				
	#define BH1750E_i2cE_SDA_0()  BH1750E_GPIO_PORT_i2cE->BRR = BH1750E_i2cE_SDA_PIN				
	
	#define BH1750E_i2cE_SDA_READ()  ((BH1750E_GPIO_PORT_i2cE->IDR & BH1750E_i2cE_SDA_PIN) != 0)	
#endif


void i2cE_Start(void);
void i2cE_Stop(void);
void i2cE_SendByte(uint8_t _ucByte);
uint8_t i2cE_ReadByte(void);
uint8_t i2cE_WaitAck(void);
void i2cE_Ack(void);
void i2cE_NAck(void);
uint8_t i2cE_CheckDevice(uint8_t _Address);


#endif

