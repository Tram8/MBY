#ifndef __i2cF_GPIO_H
#define __i2cF_GPIO_H

#include "stm32f10x.h"

#define BH1750F_i2cF_WR	0		
#define BH1750F_i2cF_RD	1		


#define BH1750F_GPIO_PORT_i2cF	GPIOA			
#define BH1750F_RCC_i2cF_PORT 	RCC_APB2Periph_GPIOA		
#define BH1750F_i2cF_SCL_PIN		GPIO_Pin_9
#define BH1750F_i2cF_SDA_PIN		GPIO_Pin_8



#if 0	
	#define BH1750F_i2cF_SCL_1()  GPIO_SetBits(BH1750F_GPIO_PORT_i2cF, BH1750F_i2cF_SCL_PIN)		
	#define BH1750F_i2cF_SCL_0()  GPIO_ResetBits(BH1750F_GPIO_PORT_i2cF, BH1750F_i2cF_SCL_PIN)		
	
	#define BH1750F_i2cF_SDA_1()  GPIO_SetBits(BH1750F_GPIO_PORT_i2cF, BH1750F_i2cF_SDA_PIN)		
	#define BH1750F_i2cF_SDA_0()  GPIO_ResetBits(BH1750F_GPIO_PORT_i2cF, BH1750F_i2cF_SDA_PIN)		
	
	#define BH1750F_i2cF_SDA_READ()  GPIO_ReadInputDataBit(BH1750F_GPIO_PORT_i2cF, BH1750F_i2cF_SDA_PIN)	
#else	
	#define BH1750F_i2cF_SCL_1()  BH1750F_GPIO_PORT_i2cF->BSRR = BH1750F_i2cF_SCL_PIN				
	#define BH1750F_i2cF_SCL_0()  BH1750F_GPIO_PORT_i2cF->BRR = BH1750F_i2cF_SCL_PIN				
	
	#define BH1750F_i2cF_SDA_1()  BH1750F_GPIO_PORT_i2cF->BSRR = BH1750F_i2cF_SDA_PIN				
	#define BH1750F_i2cF_SDA_0()  BH1750F_GPIO_PORT_i2cF->BRR = BH1750F_i2cF_SDA_PIN				
	
	#define BH1750F_i2cF_SDA_READ()  ((BH1750F_GPIO_PORT_i2cF->IDR & BH1750F_i2cF_SDA_PIN) != 0)	
#endif


void i2cF_Start(void);
void i2cF_Stop(void);
void i2cF_SendByte(uint8_t _ucByte);
uint8_t i2cF_ReadByte(void);
uint8_t i2cF_WaitAck(void);
void i2cF_Ack(void);
void i2cF_NAck(void);
uint8_t i2cF_CheckDevice(uint8_t _Address);


#endif

