
#include "./i2c_BH1750/i2cC_BH1750C_gpio.h"


static void i2cC_BH1750C_GPIOConfig(void);

static void i2cC_Delay(void)
{
	uint8_t i;

	for (i = 0; i < 10; i++);
}

void i2cC_Start(void)
{
	BH1750C_i2cC_SDA_1();
	BH1750C_i2cC_SCL_1();
	i2cC_Delay();
	BH1750C_i2cC_SDA_0();
	i2cC_Delay();
	BH1750C_i2cC_SCL_0();
	i2cC_Delay();
}

void i2cC_Stop(void)
{
	BH1750C_i2cC_SDA_0();
	BH1750C_i2cC_SCL_1();
	i2cC_Delay();
	BH1750C_i2cC_SDA_1();
}

void i2cC_SendByte(uint8_t _ucByte)
{
	uint8_t i;

	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)
		{
			BH1750C_i2cC_SDA_1();
		}
		else
		{
			BH1750C_i2cC_SDA_0();
		}
		i2cC_Delay();
		BH1750C_i2cC_SCL_1();
		i2cC_Delay();	
		BH1750C_i2cC_SCL_0();
		if (i == 7)
		{
			 BH1750C_i2cC_SDA_1(); 
		}
		_ucByte <<= 1;	
		i2cC_Delay();
	}
}

uint8_t i2cC_ReadByte(void)
{
	uint8_t i;
	uint8_t value;

	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		BH1750C_i2cC_SCL_1();
		i2cC_Delay();
		if (BH1750C_i2cC_SDA_READ())
		{
			value++;
		}
		BH1750C_i2cC_SCL_0();
		i2cC_Delay();
	}
	return value;
}

uint8_t i2cC_WaitAck(void)
{
	uint8_t re;

	BH1750C_i2cC_SDA_1();	
	i2cC_Delay();
	BH1750C_i2cC_SCL_1();	
	i2cC_Delay();
	if (BH1750C_i2cC_SDA_READ())	
		re = 1;
	else
		re = 0;
	BH1750C_i2cC_SCL_0();
	i2cC_Delay();
	return re;
}

void i2cC_Ack(void)
{
	BH1750C_i2cC_SDA_0();	
	i2cC_Delay();
	BH1750C_i2cC_SCL_1();	
	i2cC_Delay();
	BH1750C_i2cC_SCL_0();
	i2cC_Delay();
	BH1750C_i2cC_SDA_1();	
}

void i2cC_NAck(void)
{
	BH1750C_i2cC_SDA_1();	
	i2cC_Delay();
	BH1750C_i2cC_SCL_1();	
	i2cC_Delay();
	BH1750C_i2cC_SCL_0();
	i2cC_Delay();	
}

static void i2cC_BH1750C_GPIOConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(BH1750C_RCC_i2cC_PORT, ENABLE);	

	GPIO_InitStructure.GPIO_Pin = BH1750C_i2cC_SCL_PIN | BH1750C_i2cC_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	
	GPIO_Init(BH1750C_GPIO_PORT_i2cC, &GPIO_InitStructure);

	i2cC_Stop();
}

uint8_t i2cC_CheckDevice(uint8_t _Address)
{
	uint8_t ucAck;

	i2cC_BH1750C_GPIOConfig();		

	i2cC_Start();		

	i2cC_SendByte(_Address | BH1750C_i2cC_WR);
	ucAck = i2cC_WaitAck();	

	i2cC_Stop();			

	return ucAck;
}
