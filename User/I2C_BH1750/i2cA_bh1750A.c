#include "./i2c_BH1750/i2cA_BH1750A.h"

uint8_t BH1750A_Byte_Write(uint8_t data)
{
	i2cA_Start();
	i2cA_SendByte(BH1750A_Addr|0);
	if(i2cA_WaitAck()==1)
		return 1;
	i2cA_SendByte(data);
	if(i2cA_WaitAck()==1)
		return 2;
	i2cA_Stop();
	return 0;
}

uint16_t BH1750A_Read_Measure(void)
{
	uint16_t receive_data=0; 
	i2cA_Start();
	i2cA_SendByte(BH1750A_Addr|1);
	if(i2cA_WaitAck()==1)
		return 0;
	receive_data=i2cA_ReadByte();
	i2cA_Ack();
	receive_data=(receive_data<<8)+i2cA_ReadByte();
	i2cA_NAck();
	i2cA_Stop();
	return receive_data;	
}

void BH1750A_Power_ON(void)
{
	BH1750A_Byte_Write(POWER_ON);
}

void BH1750A_Power_OFF(void)
{
	BH1750A_Byte_Write(POWER_OFF);
}

void BH1750A_RESET(void)
{
	BH1750A_Byte_Write(MODULE_RESET);
}

void BH1750A_Init(void)
{
	BH1750A_Power_ON();	
	BH1750A_Byte_Write(Measure_Mode);
	SysTick_Delay_ms(120);
}

float LIghtA_Intensity(void)
{
	return (float)(BH1750A_Read_Measure()/1.2f*Resolurtion);
}
