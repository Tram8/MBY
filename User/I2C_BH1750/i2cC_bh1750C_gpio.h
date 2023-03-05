#ifndef __i2cC_GPIO_H
#define __i2cC_GPIO_H

#include "stm32f10x.h"

#define BH1750C_i2cC_WR	0		
#define BH1750C_i2cC_RD	1		


#define BH1750C_GPIO_PORT_i2cC	GPIOB			
#define BH1750C_RCC_i2cC_PORT 	RCC_APB2Periph_GPIOB		
#define BH1750C_i2cC_SCL_PIN		GPIO_Pin_15	
#define BH1750C_i2cC_SDA_PIN		GPIO_Pin_14



#if 0	
	#define BH1750C_i2cC_SCL_1()  GPIO_SetBits(BH1750C_GPIO_PORT_i2cC, BH1750C_i2cC_SCL_PIN)		
	#define BH1750C_i2cC_SCL_0()  GPIO_ResetBits(BH1750C_GPIO_PORT_i2cC, BH1750C_i2cC_SCL_PIN)		
	
	#define BH1750C_i2cC_SDA_1()  GPIO_SetBits(BH1750C_GPIO_PORT_i2cC, BH1750C_i2cC_SDA_PIN)		
	#define BH1750C_i2cC_SDA_0()  GPIO_ResetBits(BH1750C_GPIO_PORT_i2cC, BH1750C_i2cC_SDA_PIN)		
	
	#define BH1750C_i2cC_SDA_READ()  GPIO_ReadInputDataBit(BH1750C_GPIO_PORT_i2cC, BH1750C_i2cC_SDA_PIN)	
#else	
	#define BH1750C_i2cC_SCL_1()  BH1750C_GPIO_PORT_i2cC->BSRR = BH1750C_i2cC_SCL_PIN				
	#define BH1750C_i2cC_SCL_0()  BH1750C_GPIO_PORT_i2cC->BRR = BH1750C_i2cC_SCL_PIN				
	
	#define BH1750C_i2cC_SDA_1()  BH1750C_GPIO_PORT_i2cC->BSRR = BH1750C_i2cC_SDA_PIN				
	#define BH1750C_i2cC_SDA_0()  BH1750C_GPIO_PORT_i2cC->BRR = BH1750C_i2cC_SDA_PIN				
	
	#define BH1750C_i2cC_SDA_READ()  ((BH1750C_GPIO_PORT_i2cC->IDR & BH1750C_i2cC_SDA_PIN) != 0)	
#endif


void i2cC_Start(void);
void i2cC_Stop(void);
void i2cC_SendByte(uint8_t _ucByte);
uint8_t i2cC_ReadByte(void);
uint8_t i2cC_WaitAck(void);
void i2cC_Ack(void);
void i2cC_NAck(void);
uint8_t i2cC_CheckDevice(uint8_t _Address);


#endif

