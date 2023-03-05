#ifndef __i2cH_GPIO_H
#define __i2cH_GPIO_H

#include "stm32f10x.h"

#define BH1750H_i2cH_WR	0		
#define BH1750H_i2cH_RD	1		


#define BH1750H_GPIO_PORT_i2cH	GPIOA			
#define BH1750H_RCC_i2cH_PORT 	RCC_APB2Periph_GPIOA		
#define BH1750H_i2cH_SCL_PIN		GPIO_Pin_11	
#define BH1750H_i2cH_SDA_PIN		GPIO_Pin_10



#if 0	
	#define BH1750H_i2cH_SCL_1()  GPIO_SetBits(BH1750H_GPIO_PORT_i2cH, BH1750H_i2cH_SCL_PIN)		
	#define BH1750H_i2cH_SCL_0()  GPIO_ResetBits(BH1750H_GPIO_PORT_i2cH, BH1750H_i2cH_SCL_PIN)		
	
	#define BH1750H_i2cH_SDA_1()  GPIO_SetBits(BH1750H_GPIO_PORT_i2cH, BH1750H_i2cH_SDA_PIN)		
	#define BH1750H_i2cH_SDA_0()  GPIO_ResetBits(BH1750H_GPIO_PORT_i2cH, BH1750H_i2cH_SDA_PIN)		
	
	#define BH1750H_i2cH_SDA_READ()  GPIO_ReadInputDataBit(BH1750H_GPIO_PORT_i2cH, BH1750H_i2cH_SDA_PIN)	
#else	
	#define BH1750H_i2cH_SCL_1()  BH1750H_GPIO_PORT_i2cH->BSRR = BH1750H_i2cH_SCL_PIN				
	#define BH1750H_i2cH_SCL_0()  BH1750H_GPIO_PORT_i2cH->BRR = BH1750H_i2cH_SCL_PIN				
	
	#define BH1750H_i2cH_SDA_1()  BH1750H_GPIO_PORT_i2cH->BSRR = BH1750H_i2cH_SDA_PIN				
	#define BH1750H_i2cH_SDA_0()  BH1750H_GPIO_PORT_i2cH->BRR = BH1750H_i2cH_SDA_PIN				
	
	#define BH1750H_i2cH_SDA_READ()  ((BH1750H_GPIO_PORT_i2cH->IDR & BH1750H_i2cH_SDA_PIN) != 0)	
#endif


void i2cH_Start(void);
void i2cH_Stop(void);
void i2cH_SendByte(uint8_t _ucByte);
uint8_t i2cH_ReadByte(void);
uint8_t i2cH_WaitAck(void);
void i2cH_Ack(void);
void i2cH_NAck(void);
uint8_t i2cH_CheckDevice(uint8_t _Address);


#endif

