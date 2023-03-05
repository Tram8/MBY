
#include "./i2c_BH1750/i2cA_BH1750A_gpio.h"


static void i2cA_BH1750A_GPIOConfig(void);

static void i2cA_Delay(void)
{
	uint8_t i;

	for (i = 0; i < 10; i++);
}

void i2cA_Start(void)
{
	BH1750A_i2cA_SDA_1();
	BH1750A_i2cA_SCL_1();
	i2cA_Delay();
	BH1750A_i2cA_SDA_0();
	i2cA_Delay();
	BH1750A_i2cA_SCL_0();
	i2cA_Delay();
}

void i2cA_Stop(void)
{
	BH1750A_i2cA_SDA_0();
	BH1750A_i2cA_SCL_1();
	i2cA_Delay();
	BH1750A_i2cA_SDA_1();
}

void i2cA_SendByte(uint8_t _ucByte)
{
	uint8_t i;

	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)
		{
			BH1750A_i2cA_SDA_1();
		}
		else
		{
			BH1750A_i2cA_SDA_0();
		}
		i2cA_Delay();
		BH1750A_i2cA_SCL_1();
		i2cA_Delay();	
		BH1750A_i2cA_SCL_0();
		if (i == 7)
		{
			 BH1750A_i2cA_SDA_1(); 
		}
		_ucByte <<= 1;	
		i2cA_Delay();
	}
}

uint8_t i2cA_ReadByte(void)
{
	uint8_t i;
	uint8_t value;

	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		BH1750A_i2cA_SCL_1();
		i2cA_Delay();
		if (BH1750A_i2cA_SDA_READ())
		{
			value++;
		}
		BH1750A_i2cA_SCL_0();
		i2cA_Delay();
	}
	return value;
}

uint8_t i2cA_WaitAck(void)
{
	uint8_t re;

	BH1750A_i2cA_SDA_1();	
	i2cA_Delay();
	BH1750A_i2cA_SCL_1();	
	i2cA_Delay();
	if (BH1750A_i2cA_SDA_READ())	
		re = 1;
	else
		re = 0;
	BH1750A_i2cA_SCL_0();
	i2cA_Delay();
	return re;
}

void i2cA_Ack(void)
{
	BH1750A_i2cA_SDA_0();	
	i2cA_Delay();
	BH1750A_i2cA_SCL_1();	
	i2cA_Delay();
	BH1750A_i2cA_SCL_0();
	i2cA_Delay();
	BH1750A_i2cA_SDA_1();	
}

void i2cA_NAck(void)
{
	BH1750A_i2cA_SDA_1();	
	i2cA_Delay();
	BH1750A_i2cA_SCL_1();	
	i2cA_Delay();
	BH1750A_i2cA_SCL_0();
	i2cA_Delay();	
}

static void i2cA_BH1750A_GPIOConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(BH1750A_RCC_i2cA_PORT, ENABLE);	

	GPIO_InitStructure.GPIO_Pin = BH1750A_i2cA_SCL_PIN | BH1750A_i2cA_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	
	GPIO_Init(BH1750A_GPIO_PORT_i2cA, &GPIO_InitStructure);

	i2cA_Stop();
}

uint8_t i2cA_CheckDevice(uint8_t _Address)
{
	uint8_t ucAck;

	i2cA_BH1750A_GPIOConfig();		

	i2cA_Start();		

	i2cA_SendByte(_Address | BH1750A_i2cA_WR);
	ucAck = i2cA_WaitAck();	

	i2cA_Stop();			

	return ucAck;
}
