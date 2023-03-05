
#include "./i2c_BH1750/i2cD_BH1750D_gpio.h"


static void i2cD_BH1750D_GPIOConfig(void);

static void i2cD_Delay(void)
{
	uint8_t i;

	for (i = 0; i < 10; i++);
}

void i2cD_Start(void)
{
	BH1750D_i2cD_SDA_1();
	BH1750D_i2cD_SCL_1();
	i2cD_Delay();
	BH1750D_i2cD_SDA_0();
	i2cD_Delay();
	BH1750D_i2cD_SCL_0();
	i2cD_Delay();
}

void i2cD_Stop(void)
{
	BH1750D_i2cD_SDA_0();
	BH1750D_i2cD_SCL_1();
	i2cD_Delay();
	BH1750D_i2cD_SDA_1();
}

void i2cD_SendByte(uint8_t _ucByte)
{
	uint8_t i;

	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)
		{
			BH1750D_i2cD_SDA_1();
		}
		else
		{
			BH1750D_i2cD_SDA_0();
		}
		i2cD_Delay();
		BH1750D_i2cD_SCL_1();
		i2cD_Delay();	
		BH1750D_i2cD_SCL_0();
		if (i == 7)
		{
			 BH1750D_i2cD_SDA_1(); 
		}
		_ucByte <<= 1;	
		i2cD_Delay();
	}
}

uint8_t i2cD_ReadByte(void)
{
	uint8_t i;
	uint8_t value;

	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		BH1750D_i2cD_SCL_1();
		i2cD_Delay();
		if (BH1750D_i2cD_SDA_READ())
		{
			value++;
		}
		BH1750D_i2cD_SCL_0();
		i2cD_Delay();
	}
	return value;
}

uint8_t i2cD_WaitAck(void)
{
	uint8_t re;

	BH1750D_i2cD_SDA_1();	
	i2cD_Delay();
	BH1750D_i2cD_SCL_1();	
	i2cD_Delay();
	if (BH1750D_i2cD_SDA_READ())	
		re = 1;
	else
		re = 0;
	BH1750D_i2cD_SCL_0();
	i2cD_Delay();
	return re;
}

void i2cD_Ack(void)
{
	BH1750D_i2cD_SDA_0();	
	i2cD_Delay();
	BH1750D_i2cD_SCL_1();	
	i2cD_Delay();
	BH1750D_i2cD_SCL_0();
	i2cD_Delay();
	BH1750D_i2cD_SDA_1();	
}

void i2cD_NAck(void)
{
	BH1750D_i2cD_SDA_1();	
	i2cD_Delay();
	BH1750D_i2cD_SCL_1();	
	i2cD_Delay();
	BH1750D_i2cD_SCL_0();
	i2cD_Delay();	
}

static void i2cD_BH1750D_GPIOConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(BH1750D_RCC_i2cD_PORT, ENABLE);	

	GPIO_InitStructure.GPIO_Pin = BH1750D_i2cD_SCL_PIN | BH1750D_i2cD_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	
	GPIO_Init(BH1750D_GPIO_PORT_i2cD, &GPIO_InitStructure);

	i2cD_Stop();
}

uint8_t i2cD_CheckDevice(uint8_t _Address)
{
	uint8_t ucAck;

	i2cD_BH1750D_GPIOConfig();		

	i2cD_Start();		

	i2cD_SendByte(_Address | BH1750D_i2cD_WR);
	ucAck = i2cD_WaitAck();	

	i2cD_Stop();			

	return ucAck;
}
