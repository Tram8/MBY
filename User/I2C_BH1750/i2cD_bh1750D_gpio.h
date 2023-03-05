#ifndef __i2cD_GPIO_H
#define __i2cD_GPIO_H

#include "stm32f10x.h"

#define BH1750D_i2cD_WR	0		
#define BH1750D_i2cD_RD	1		


#define BH1750D_GPIO_PORT_i2cD	GPIOB			
#define BH1750D_RCC_i2cD_PORT 	RCC_APB2Periph_GPIOB		
#define BH1750D_i2cD_SCL_PIN		GPIO_Pin_15	
#define BH1750D_i2cD_SDA_PIN		GPIO_Pin_14



#if 0	
	#define BH1750D_i2cD_SCL_1()  GPIO_SetBits(BH1750D_GPIO_PORT_i2cD, BH1750D_i2cD_SCL_PIN)		
	#define BH1750D_i2cD_SCL_0()  GPIO_ResetBits(BH1750D_GPIO_PORT_i2cD, BH1750D_i2cD_SCL_PIN)		
	
	#define BH1750D_i2cD_SDA_1()  GPIO_SetBits(BH1750D_GPIO_PORT_i2cD, BH1750D_i2cD_SDA_PIN)		
	#define BH1750D_i2cD_SDA_0()  GPIO_ResetBits(BH1750D_GPIO_PORT_i2cD, BH1750D_i2cD_SDA_PIN)		
	
	#define BH1750D_i2cD_SDA_READ()  GPIO_ReadInputDataBit(BH1750D_GPIO_PORT_i2cD, BH1750D_i2cD_SDA_PIN)	
#else	
	#define BH1750D_i2cD_SCL_1()  BH1750D_GPIO_PORT_i2cD->BSRR = BH1750D_i2cD_SCL_PIN				
	#define BH1750D_i2cD_SCL_0()  BH1750D_GPIO_PORT_i2cD->BRR = BH1750D_i2cD_SCL_PIN				
	
	#define BH1750D_i2cD_SDA_1()  BH1750D_GPIO_PORT_i2cD->BSRR = BH1750D_i2cD_SDA_PIN				
	#define BH1750D_i2cD_SDA_0()  BH1750D_GPIO_PORT_i2cD->BRR = BH1750D_i2cD_SDA_PIN				
	
	#define BH1750D_i2cD_SDA_READ()  ((BH1750D_GPIO_PORT_i2cD->IDR & BH1750D_i2cD_SDA_PIN) != 0)	
#endif


void i2cD_Start(void);
void i2cD_Stop(void);
void i2cD_SendByte(uint8_t _ucByte);
uint8_t i2cD_ReadByte(void);
uint8_t i2cD_WaitAck(void);
void i2cD_Ack(void);
void i2cD_NAck(void);
uint8_t i2cD_CheckDevice(uint8_t _Address);


#endif

