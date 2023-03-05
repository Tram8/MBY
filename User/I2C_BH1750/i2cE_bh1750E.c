#include "./i2c_BH1750/i2cE_BH1750E.h"

uint8_t BH1750E_Byte_Write(uint8_t data)
{
	i2cE_Start();
	i2cE_SendByte(BH1750E_Addr|0);
	if(i2cE_WaitAck()==1)
		return 1;
	i2cE_SendByte(data);
	if(i2cE_WaitAck()==1)
		return 2;
	i2cE_Stop();
	return 0;
}

uint16_t BH1750E_Read_Measure(void)
{
	uint16_t receive_data=0; 
	i2cE_Start();
	i2cE_SendByte(BH1750E_Addr|1);
	if(i2cE_WaitAck()==1)
		return 0;
	receive_data=i2cE_ReadByte();
	i2cE_Ack();
	receive_data=(receive_data<<8)+i2cE_ReadByte();
	i2cE_NAck();
	i2cE_Stop();
	return receive_data;	
}

void BH1750E_Power_ON(void)
{
	BH1750E_Byte_Write(POWER_ON);
}

void BH1750E_Power_OFF(void)
{
	BH1750E_Byte_Write(POWER_OFF);
}

void BH1750E_RESET(void)
{
	BH1750E_Byte_Write(MODULE_RESET);
}

void BH1750E_Init(void)
{
	BH1750E_Power_ON();	
	BH1750E_Byte_Write(Measure_Mode);
	SysTick_Delay_ms(120);
}

float LIghtE_Intensity(void)
{
	return (float)(BH1750E_Read_Measure()/1.2f*Resolurtion);
}
