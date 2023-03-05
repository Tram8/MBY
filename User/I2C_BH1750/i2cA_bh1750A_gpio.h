#ifndef __i2cA_GPIO_H
#define __i2cA_GPIO_H

#include "stm32f10x.h"

#define BH1750A_i2cA_WR	0		
#define BH1750A_i2cA_RD	1		


#define BH1750A_GPIO_PORT_i2cA	GPIOB			
#define BH1750A_RCC_i2cA_PORT 	RCC_APB2Periph_GPIOB		
#define BH1750A_i2cA_SCL_PIN		GPIO_Pin_13	
#define BH1750A_i2cA_SDA_PIN		GPIO_Pin_12



#if 0	
	#define BH1750A_i2cA_SCL_1()  GPIO_SetBits(BH1750A_GPIO_PORT_i2cA, BH1750A_i2cA_SCL_PIN)		
	#define BH1750A_i2cA_SCL_0()  GPIO_ResetBits(BH1750A_GPIO_PORT_i2cA, BH1750A_i2cA_SCL_PIN)		
	
	#define BH1750A_i2cA_SDA_1()  GPIO_SetBits(BH1750A_GPIO_PORT_i2cA, BH1750A_i2cA_SDA_PIN)		
	#define BH1750A_i2cA_SDA_0()  GPIO_ResetBits(BH1750A_GPIO_PORT_i2cA, BH1750A_i2cA_SDA_PIN)		
	
	#define BH1750A_i2cA_SDA_READ()  GPIO_ReadInputDataBit(BH1750A_GPIO_PORT_i2cA, BH1750A_i2cA_SDA_PIN)	
#else	
	#define BH1750A_i2cA_SCL_1()  BH1750A_GPIO_PORT_i2cA->BSRR = BH1750A_i2cA_SCL_PIN				
	#define BH1750A_i2cA_SCL_0()  BH1750A_GPIO_PORT_i2cA->BRR = BH1750A_i2cA_SCL_PIN				
	
	#define BH1750A_i2cA_SDA_1()  BH1750A_GPIO_PORT_i2cA->BSRR = BH1750A_i2cA_SDA_PIN				
	#define BH1750A_i2cA_SDA_0()  BH1750A_GPIO_PORT_i2cA->BRR = BH1750A_i2cA_SDA_PIN				
	
	#define BH1750A_i2cA_SDA_READ()  ((BH1750A_GPIO_PORT_i2cA->IDR & BH1750A_i2cA_SDA_PIN) != 0)	
#endif


void i2cA_Start(void);
void i2cA_Stop(void);
void i2cA_SendByte(uint8_t _ucByte);
uint8_t i2cA_ReadByte(void);
uint8_t i2cA_WaitAck(void);
void i2cA_Ack(void);
void i2cA_NAck(void);
uint8_t i2cA_CheckDevice(uint8_t _Address);


#endif

