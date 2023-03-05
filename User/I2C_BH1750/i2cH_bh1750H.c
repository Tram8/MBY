#include "./i2c_BH1750/i2cH_BH1750H.h"

uint8_t BH1750H_Byte_Write(uint8_t data)
{
	i2cH_Start();
	i2cH_SendByte(BH1750H_Addr|0);
	if(i2cH_WaitAck()==1)
		return 1;
	i2cH_SendByte(data);
	if(i2cH_WaitAck()==1)
		return 2;
	i2cH_Stop();
	return 0;
}

uint16_t BH1750H_Read_Measure(void)
{
	uint16_t receive_data=0; 
	i2cH_Start();
	i2cH_SendByte(BH1750H_Addr|1);
	if(i2cH_WaitAck()==1)
		return 0;
	receive_data=i2cH_ReadByte();
	i2cH_Ack();
	receive_data=(receive_data<<8)+i2cH_ReadByte();
	i2cH_NAck();
	i2cH_Stop();
	return receive_data;	
}

void BH1750H_Power_ON(void)
{
	BH1750H_Byte_Write(POWER_ON);
}

void BH1750H_Power_OFF(void)
{
	BH1750H_Byte_Write(POWER_OFF);
}

void BH1750H_RESET(void)
{
	BH1750H_Byte_Write(MODULE_RESET);
}

void BH1750H_Init(void)
{
	BH1750H_Power_ON();	
	BH1750H_Byte_Write(Measure_Mode);
	SysTick_Delay_ms(120);
}

float LIghtH_Intensity(void)
{
	return (float)(BH1750H_Read_Measure()/1.2f*Resolurtion);
}
