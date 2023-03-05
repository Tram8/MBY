
#include "./i2c_BH1750/i2cG_BH1750G_gpio.h"


static void i2cG_BH1750G_GPIOConfig(void);

static void i2cG_Delay(void)
{
	uint8_t i;

	for (i = 0; i < 10; i++);
}

void i2cG_Start(void)
{
	BH1750G_i2cG_SDA_1();
	BH1750G_i2cG_SCL_1();
	i2cG_Delay();
	BH1750G_i2cG_SDA_0();
	i2cG_Delay();
	BH1750G_i2cG_SCL_0();
	i2cG_Delay();
}

void i2cG_Stop(void)
{
	BH1750G_i2cG_SDA_0();
	BH1750G_i2cG_SCL_1();
	i2cG_Delay();
	BH1750G_i2cG_SDA_1();
}

void i2cG_SendByte(uint8_t _ucByte)
{
	uint8_t i;

	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)
		{
			BH1750G_i2cG_SDA_1();
		}
		else
		{
			BH1750G_i2cG_SDA_0();
		}
		i2cG_Delay();
		BH1750G_i2cG_SCL_1();
		i2cG_Delay();	
		BH1750G_i2cG_SCL_0();
		if (i == 7)
		{
			 BH1750G_i2cG_SDA_1(); 
		}
		_ucByte <<= 1;	
		i2cG_Delay();
	}
}

uint8_t i2cG_ReadByte(void)
{
	uint8_t i;
	uint8_t value;

	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		BH1750G_i2cG_SCL_1();
		i2cG_Delay();
		if (BH1750G_i2cG_SDA_READ())
		{
			value++;
		}
		BH1750G_i2cG_SCL_0();
		i2cG_Delay();
	}
	return value;
}

uint8_t i2cG_WaitAck(void)
{
	uint8_t re;

	BH1750G_i2cG_SDA_1();	
	i2cG_Delay();
	BH1750G_i2cG_SCL_1();	
	i2cG_Delay();
	if (BH1750G_i2cG_SDA_READ())	
		re = 1;
	else
		re = 0;
	BH1750G_i2cG_SCL_0();
	i2cG_Delay();
	return re;
}

void i2cG_Ack(void)
{
	BH1750G_i2cG_SDA_0();	
	i2cG_Delay();
	BH1750G_i2cG_SCL_1();	
	i2cG_Delay();
	BH1750G_i2cG_SCL_0();
	i2cG_Delay();
	BH1750G_i2cG_SDA_1();	
}

void i2cG_NAck(void)
{
	BH1750G_i2cG_SDA_1();	
	i2cG_Delay();
	BH1750G_i2cG_SCL_1();	
	i2cG_Delay();
	BH1750G_i2cG_SCL_0();
	i2cG_Delay();	
}

static void i2cG_BH1750G_GPIOConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(BH1750G_RCC_i2cG_PORT, ENABLE);	

	GPIO_InitStructure.GPIO_Pin = BH1750G_i2cG_SCL_PIN | BH1750G_i2cG_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	
	GPIO_Init(BH1750G_GPIO_PORT_i2cG, &GPIO_InitStructure);

	i2cG_Stop();
}

uint8_t i2cG_CheckDevice(uint8_t _Address)
{
	uint8_t ucAck;

	i2cG_BH1750G_GPIOConfig();		

	i2cG_Start();		

	i2cG_SendByte(_Address | BH1750G_i2cG_WR);
	ucAck = i2cG_WaitAck();	

	i2cG_Stop();			

	return ucAck;
}
