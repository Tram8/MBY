
#include "./i2c_BH1750/i2cH_BH1750H_gpio.h"


static void i2cH_BH1750H_GPIOConfig(void);

static void i2cH_Delay(void)
{
	uint8_t i;

	for (i = 0; i < 10; i++);
}

void i2cH_Start(void)
{
	BH1750H_i2cH_SDA_1();
	BH1750H_i2cH_SCL_1();
	i2cH_Delay();
	BH1750H_i2cH_SDA_0();
	i2cH_Delay();
	BH1750H_i2cH_SCL_0();
	i2cH_Delay();
}

void i2cH_Stop(void)
{
	BH1750H_i2cH_SDA_0();
	BH1750H_i2cH_SCL_1();
	i2cH_Delay();
	BH1750H_i2cH_SDA_1();
}

void i2cH_SendByte(uint8_t _ucByte)
{
	uint8_t i;

	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)
		{
			BH1750H_i2cH_SDA_1();
		}
		else
		{
			BH1750H_i2cH_SDA_0();
		}
		i2cH_Delay();
		BH1750H_i2cH_SCL_1();
		i2cH_Delay();	
		BH1750H_i2cH_SCL_0();
		if (i == 7)
		{
			 BH1750H_i2cH_SDA_1(); 
		}
		_ucByte <<= 1;	
		i2cH_Delay();
	}
}

uint8_t i2cH_ReadByte(void)
{
	uint8_t i;
	uint8_t value;

	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		BH1750H_i2cH_SCL_1();
		i2cH_Delay();
		if (BH1750H_i2cH_SDA_READ())
		{
			value++;
		}
		BH1750H_i2cH_SCL_0();
		i2cH_Delay();
	}
	return value;
}

uint8_t i2cH_WaitAck(void)
{
	uint8_t re;

	BH1750H_i2cH_SDA_1();	
	i2cH_Delay();
	BH1750H_i2cH_SCL_1();	
	i2cH_Delay();
	if (BH1750H_i2cH_SDA_READ())	
		re = 1;
	else
		re = 0;
	BH1750H_i2cH_SCL_0();
	i2cH_Delay();
	return re;
}

void i2cH_Ack(void)
{
	BH1750H_i2cH_SDA_0();	
	i2cH_Delay();
	BH1750H_i2cH_SCL_1();	
	i2cH_Delay();
	BH1750H_i2cH_SCL_0();
	i2cH_Delay();
	BH1750H_i2cH_SDA_1();	
}

void i2cH_NAck(void)
{
	BH1750H_i2cH_SDA_1();	
	i2cH_Delay();
	BH1750H_i2cH_SCL_1();	
	i2cH_Delay();
	BH1750H_i2cH_SCL_0();
	i2cH_Delay();	
}

static void i2cH_BH1750H_GPIOConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(BH1750H_RCC_i2cH_PORT, ENABLE);	

	GPIO_InitStructure.GPIO_Pin = BH1750H_i2cH_SCL_PIN | BH1750H_i2cH_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	
	GPIO_Init(BH1750H_GPIO_PORT_i2cH, &GPIO_InitStructure);

	i2cH_Stop();
}

uint8_t i2cH_CheckDevice(uint8_t _Address)
{
	uint8_t ucAck;

	i2cH_BH1750H_GPIOConfig();		

	i2cH_Start();		

	i2cH_SendByte(_Address | BH1750H_i2cH_WR);
	ucAck = i2cH_WaitAck();	

	i2cH_Stop();			

	return ucAck;
}
