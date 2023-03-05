#include "./i2c_BH1750/i2cF_BH1750F.h"

uint8_t BH1750F_Byte_Write(uint8_t data)
{
	i2cF_Start();
	i2cF_SendByte(BH1750F_Addr|0);
	if(i2cF_WaitAck()==1)
		return 1;
	i2cF_SendByte(data);
	if(i2cF_WaitAck()==1)
		return 2;
	i2cF_Stop();
	return 0;
}

uint16_t BH1750F_Read_Measure(void)
{
	uint16_t receive_data=0; 
	i2cF_Start();
	i2cF_SendByte(BH1750F_Addr|1);
	if(i2cF_WaitAck()==1)
		return 0;
	receive_data=i2cF_ReadByte();
	i2cF_Ack();
	receive_data=(receive_data<<8)+i2cF_ReadByte();
	i2cF_NAck();
	i2cF_Stop();
	return receive_data;	
}

void BH1750F_Power_ON(void)
{
	BH1750F_Byte_Write(POWER_ON);
}

void BH1750F_Power_OFF(void)
{
	BH1750F_Byte_Write(POWER_OFF);
}

void BH1750F_RESET(void)
{
	BH1750F_Byte_Write(MODULE_RESET);
}

void BH1750F_Init(void)
{
	BH1750F_Power_ON();	
	BH1750F_Byte_Write(Measure_Mode);
	SysTick_Delay_ms(120);
}

float LIghtF_Intensity(void)
{
	return (float)(BH1750F_Read_Measure()/1.2f*Resolurtion);
}
