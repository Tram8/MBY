
#include "./i2c_BH1750/i2cE_BH1750E_gpio.h"


static void i2cE_BH1750E_GPIOConfig(void);

static void i2cE_Delay(void)
{
	uint8_t i;

	for (i = 0; i < 10; i++);
}

void i2cE_Start(void)
{
	BH1750E_i2cE_SDA_1();
	BH1750E_i2cE_SCL_1();
	i2cE_Delay();
	BH1750E_i2cE_SDA_0();
	i2cE_Delay();
	BH1750E_i2cE_SCL_0();
	i2cE_Delay();
}

void i2cE_Stop(void)
{
	BH1750E_i2cE_SDA_0();
	BH1750E_i2cE_SCL_1();
	i2cE_Delay();
	BH1750E_i2cE_SDA_1();
}

void i2cE_SendByte(uint8_t _ucByte)
{
	uint8_t i;

	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)
		{
			BH1750E_i2cE_SDA_1();
		}
		else
		{
			BH1750E_i2cE_SDA_0();
		}
		i2cE_Delay();
		BH1750E_i2cE_SCL_1();
		i2cE_Delay();	
		BH1750E_i2cE_SCL_0();
		if (i == 7)
		{
			 BH1750E_i2cE_SDA_1(); 
		}
		_ucByte <<= 1;	
		i2cE_Delay();
	}
}

uint8_t i2cE_ReadByte(void)
{
	uint8_t i;
	uint8_t value;

	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		BH1750E_i2cE_SCL_1();
		i2cE_Delay();
		if (BH1750E_i2cE_SDA_READ())
		{
			value++;
		}
		BH1750E_i2cE_SCL_0();
		i2cE_Delay();
	}
	return value;
}

uint8_t i2cE_WaitAck(void)
{
	uint8_t re;

	BH1750E_i2cE_SDA_1();	
	i2cE_Delay();
	BH1750E_i2cE_SCL_1();	
	i2cE_Delay();
	if (BH1750E_i2cE_SDA_READ())	
		re = 1;
	else
		re = 0;
	BH1750E_i2cE_SCL_0();
	i2cE_Delay();
	return re;
}

void i2cE_Ack(void)
{
	BH1750E_i2cE_SDA_0();	
	i2cE_Delay();
	BH1750E_i2cE_SCL_1();	
	i2cE_Delay();
	BH1750E_i2cE_SCL_0();
	i2cE_Delay();
	BH1750E_i2cE_SDA_1();	
}

void i2cE_NAck(void)
{
	BH1750E_i2cE_SDA_1();	
	i2cE_Delay();
	BH1750E_i2cE_SCL_1();	
	i2cE_Delay();
	BH1750E_i2cE_SCL_0();
	i2cE_Delay();	
}

static void i2cE_BH1750E_GPIOConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(BH1750E_RCC_i2cE_PORT, ENABLE);	

	GPIO_InitStructure.GPIO_Pin = BH1750E_i2cE_SCL_PIN | BH1750E_i2cE_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	
	GPIO_Init(BH1750E_GPIO_PORT_i2cE, &GPIO_InitStructure);

	i2cE_Stop();
}

uint8_t i2cE_CheckDevice(uint8_t _Address)
{
	uint8_t ucAck;

	i2cE_BH1750E_GPIOConfig();		

	i2cE_Start();		

	i2cE_SendByte(_Address | BH1750E_i2cE_WR);
	ucAck = i2cE_WaitAck();	

	i2cE_Stop();			

	return ucAck;
}
