#include "./i2c_BH1750/i2cC_BH1750C.h"

uint8_t BH1750C_Byte_Write(uint8_t data)
{
	i2cC_Start();
	i2cC_SendByte(BH1750C_Addr|0);
	if(i2cC_WaitAck()==1)
		return 1;
	i2cC_SendByte(data);
	if(i2cC_WaitAck()==1)
		return 2;
	i2cC_Stop();
	return 0;
}

uint16_t BH1750C_Read_Measure(void)
{
	uint16_t receive_data=0; 
	i2cC_Start();
	i2cC_SendByte(BH1750C_Addr|1);
	if(i2cC_WaitAck()==1)
		return 0;
	receive_data=i2cC_ReadByte();
	i2cC_Ack();
	receive_data=(receive_data<<8)+i2cC_ReadByte();
	i2cC_NAck();
	i2cC_Stop();
	return receive_data;	
}

void BH1750C_Power_ON(void)
{
	BH1750C_Byte_Write(POWER_ON);
}

void BH1750C_Power_OFF(void)
{
	BH1750C_Byte_Write(POWER_OFF);
}

void BH1750C_RESET(void)
{
	BH1750C_Byte_Write(MODULE_RESET);
}

void BH1750C_Init(void)
{
	BH1750C_Power_ON();	
	BH1750C_Byte_Write(Measure_Mode);
	SysTick_Delay_ms(120);
}

float LIghtC_Intensity(void)
{
	return (float)(BH1750C_Read_Measure()/1.2f*Resolurtion);
}
