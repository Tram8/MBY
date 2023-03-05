
#include "./i2c_BH1750/i2cF_BH1750F_gpio.h"


static void i2cF_BH1750F_GPIOConfig(void);

static void i2cF_Delay(void)
{
	uint8_t i;

	for (i = 0; i < 10; i++);
}

void i2cF_Start(void)
{
	BH1750F_i2cF_SDA_1();
	BH1750F_i2cF_SCL_1();
	i2cF_Delay();
	BH1750F_i2cF_SDA_0();
	i2cF_Delay();
	BH1750F_i2cF_SCL_0();
	i2cF_Delay();
}

void i2cF_Stop(void)
{
	BH1750F_i2cF_SDA_0();
	BH1750F_i2cF_SCL_1();
	i2cF_Delay();
	BH1750F_i2cF_SDA_1();
}

void i2cF_SendByte(uint8_t _ucByte)
{
	uint8_t i;

	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)
		{
			BH1750F_i2cF_SDA_1();
		}
		else
		{
			BH1750F_i2cF_SDA_0();
		}
		i2cF_Delay();
		BH1750F_i2cF_SCL_1();
		i2cF_Delay();	
		BH1750F_i2cF_SCL_0();
		if (i == 7)
		{
			 BH1750F_i2cF_SDA_1(); 
		}
		_ucByte <<= 1;	
		i2cF_Delay();
	}
}

uint8_t i2cF_ReadByte(void)
{
	uint8_t i;
	uint8_t value;

	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		BH1750F_i2cF_SCL_1();
		i2cF_Delay();
		if (BH1750F_i2cF_SDA_READ())
		{
			value++;
		}
		BH1750F_i2cF_SCL_0();
		i2cF_Delay();
	}
	return value;
}

uint8_t i2cF_WaitAck(void)
{
	uint8_t re;

	BH1750F_i2cF_SDA_1();	
	i2cF_Delay();
	BH1750F_i2cF_SCL_1();	
	i2cF_Delay();
	if (BH1750F_i2cF_SDA_READ())	
		re = 1;
	else
		re = 0;
	BH1750F_i2cF_SCL_0();
	i2cF_Delay();
	return re;
}

void i2cF_Ack(void)
{
	BH1750F_i2cF_SDA_0();	
	i2cF_Delay();
	BH1750F_i2cF_SCL_1();	
	i2cF_Delay();
	BH1750F_i2cF_SCL_0();
	i2cF_Delay();
	BH1750F_i2cF_SDA_1();	
}

void i2cF_NAck(void)
{
	BH1750F_i2cF_SDA_1();	
	i2cF_Delay();
	BH1750F_i2cF_SCL_1();	
	i2cF_Delay();
	BH1750F_i2cF_SCL_0();
	i2cF_Delay();	
}

static void i2cF_BH1750F_GPIOConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(BH1750F_RCC_i2cF_PORT, ENABLE);	

	GPIO_InitStructure.GPIO_Pin = BH1750F_i2cF_SCL_PIN | BH1750F_i2cF_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	
	GPIO_Init(BH1750F_GPIO_PORT_i2cF, &GPIO_InitStructure);

	i2cF_Stop();
}

uint8_t i2cF_CheckDevice(uint8_t _Address)
{
	uint8_t ucAck;

	i2cF_BH1750F_GPIOConfig();		

	i2cF_Start();		

	i2cF_SendByte(_Address | BH1750F_i2cF_WR);
	ucAck = i2cF_WaitAck();	

	i2cF_Stop();			

	return ucAck;
}
