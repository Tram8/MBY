#include "./i2c_BH1750/i2cG_BH1750G.h"

uint8_t BH1750G_Byte_Write(uint8_t data)
{
	i2cG_Start();
	i2cG_SendByte(BH1750G_Addr|0);
	if(i2cG_WaitAck()==1)
		return 1;
	i2cG_SendByte(data);
	if(i2cG_WaitAck()==1)
		return 2;
	i2cG_Stop();
	return 0;
}

uint16_t BH1750G_Read_Measure(void)
{
	uint16_t receive_data=0; 
	i2cG_Start();
	i2cG_SendByte(BH1750G_Addr|1);
	if(i2cG_WaitAck()==1)
		return 0;
	receive_data=i2cG_ReadByte();
	i2cG_Ack();
	receive_data=(receive_data<<8)+i2cG_ReadByte();
	i2cG_NAck();
	i2cG_Stop();
	return receive_data;	
}

void BH1750G_Power_ON(void)
{
	BH1750G_Byte_Write(POWER_ON);
}

void BH1750G_Power_OFF(void)
{
	BH1750G_Byte_Write(POWER_OFF);
}

void BH1750G_RESET(void)
{
	BH1750G_Byte_Write(MODULE_RESET);
}

void BH1750G_Init(void)
{
	BH1750G_Power_ON();	
	BH1750G_Byte_Write(Measure_Mode);
	SysTick_Delay_ms(120);
}

float LIghtG_Intensity(void)
{
	return (float)(BH1750G_Read_Measure()/1.2f*Resolurtion);
}
