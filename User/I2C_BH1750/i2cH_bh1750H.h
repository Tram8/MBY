#ifndef __BH1750H_i2cH_H
#define __BH1750H_i2cH_H

#include "stm32f10x.h"
#include "./i2c_BH1750/i2cH_BH1750H_gpio.h"
#include "./SYSTICK/systick.h"

#define BH1750H_Addr				0xB8  //H B8  L 46

#define POWER_OFF					0x00
#define POWER_ON					0x01
#define MODULE_RESET			0x07
#define	CONTINUE_H_MODE		0x10
#define CONTINUE_H_MODE2	0x11
#define CONTINUE_L_MODE		0x13
#define ONE_TIME_H_MODE		0x20
#define ONE_TIME_H_MODE2	0x21
#define ONE_TIME_L_MODE		0x23

#define Measure_Mode			CONTINUE_H_MODE2

#if ((Measure_Mode==CONTINUE_H_MODE2)|(Measure_Mode==ONE_TIME_H_MODE2))
	#define Resolurtion		1  //0.5
#elif ((Measure_Mode==CONTINUE_H_MODE)|(Measure_Mode==ONE_TIME_H_MODE))
	#define Resolurtion		1  //1
#elif ((Measure_Mode==CONTINUE_L_MODE)|(Measure_Mode==ONE_TIME_L_MODE))
	#define Resolurtion		1  //4
#endif

void BH1750H_Init(void);			
float LIghtH_Intensity(void);	
uint8_t BH1750H_Byte_Write(uint8_t data);
uint16_t BH1750H_Read_Measure(void);
void BH1750H_Power_ON(void);
void BH1750H_Power_OFF(void);
void BH1750H_RESET(void);

#endif /* __BH1750H_i2cH_H */

