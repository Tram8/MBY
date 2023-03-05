#include "./i2c_BH1750/i2cD_BH1750D.h"

uint8_t BH1750D_Byte_Write(uint8_t data)
{
	i2cD_Start();
	i2cD_SendByte(BH1750D_Addr|0);
	if(i2cD_WaitAck()==1)
		return 1;
	i2cD_SendByte(data);
	if(i2cD_WaitAck()==1)
		return 2;
	i2cD_Stop();
	return 0;
}

uint16_t BH1750D_Read_Measure(void)
{
	uint16_t receive_data=0; 
	i2cD_Start();
	i2cD_SendByte(BH1750D_Addr|1);
	if(i2cD_WaitAck()==1)
		return 0;
	receive_data=i2cD_ReadByte();
	i2cD_Ack();
	receive_data=(receive_data<<8)+i2cD_ReadByte();
	i2cD_NAck();
	i2cD_Stop();
	return receive_data;	
}

void BH1750D_Power_ON(void)
{
	BH1750D_Byte_Write(POWER_ON);
}

void BH1750D_Power_OFF(void)
{
	BH1750D_Byte_Write(POWER_OFF);
}

void BH1750D_RESET(void)
{
	BH1750D_Byte_Write(MODULE_RESET);
}

void BH1750D_Init(void)
{
	BH1750D_Power_ON();	
	BH1750D_Byte_Write(Measure_Mode);
	SysTick_Delay_ms(120);
}

float LIghtD_Intensity(void)
{
	return (float)(BH1750D_Read_Measure()/1.2f*Resolurtion);
}
