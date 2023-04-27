#include <stdio.h>
#include "stm32f10x.h"
#include "./USART/usart.h"
#include "./SYSTICK/systick.h"
#include "./i2c_BH1750/i2cA_BH1750A_gpio.h"
#include "./i2c_BH1750/i2cA_BH1750A.h"
#include "./I2C_BH1750/i2cB_bh1750B_gpio.h"
#include "./I2C_BH1750/i2cB_bh1750B.h"
#include "./I2C_BH1750/i2cC_bh1750C_gpio.h"
#include "./I2C_BH1750/i2cC_bh1750C.h"
#include "./I2C_BH1750/i2cD_bh1750D_gpio.h"
#include "./I2C_BH1750/i2cD_bh1750D.h"
#include "./I2C_BH1750/i2cE_bh1750E_gpio.h"
#include "./I2C_BH1750/i2cE_bh1750E.h"
#include "./I2C_BH1750/i2cF_bh1750F_gpio.h"
#include "./I2C_BH1750/i2cF_bh1750F.h"
#include "./I2C_BH1750/i2cG_bh1750G_gpio.h"
#include "./I2C_BH1750/i2cG_bh1750G.h"
#include "./I2C_BH1750/i2cH_bh1750H_gpio.h"
#include "./I2C_BH1750/i2cH_bh1750H.h"
#include "./OLED/OLED.h"
#include "./step/step.h"
#include "./jdq/jdq.h"
#include <cmath>

//u8 page;
float dataA[13];
float dataB[13];
float dataC[13];
float dataD[13];
float dataE[13];
float dataF[13];
float dataG[13];
float dataH[13];

float dataA2[13];
float dataB2[13];
float dataC2[13];
float dataD2[13];
float dataE2[13];
float dataF2[13];
float dataG2[13];
float dataH2[13];

float TA[13];
float TB[13];
float TC[13];
float TD[13];
float TE[13];
float TF[13];
float TG[13];
float TH[13];

float ODA[13];
float ODB[13];
float ODC[13];
float ODD[13];
float ODE[13];
float ODF[13];
float ODG[13];
float ODH[13];


void BH1750Init(void)
{
	if(i2cA_CheckDevice(BH1750A_Addr)==0)
  printf("A");
  else printf("0");
	BH1750A_Init();
	  	if(i2cB_CheckDevice(BH1750B_Addr)==0)
  printf("B");
  else printf("0");
	BH1750B_Init();	
		if(i2cC_CheckDevice(BH1750C_Addr)==0)
  printf("C");
  else printf("0");
	BH1750C_Init();
		if(i2cD_CheckDevice(BH1750D_Addr)==0)
    printf("D");
    else printf("0");
	  BH1750D_Init();
		if(i2cE_CheckDevice(BH1750E_Addr)==0)
  printf("E");
  else printf("0");
	BH1750E_Init();
		if(i2cF_CheckDevice(BH1750F_Addr)==0)
  printf("F");
  else printf("0");
	BH1750F_Init();
		if(i2cG_CheckDevice(BH1750G_Addr)==0)
  printf("G");
  else printf("0");
	BH1750G_Init();
		if(i2cH_CheckDevice(BH1750H_Addr)==0)
  printf("H");
  else printf("0");
	BH1750H_Init();
}
void sampling_1(void)
{		
	BH1750Init();
	    SysTick_Delay_ms(1000);
	Stepturn(21000,1);//  18533
  	    SysTick_Delay_ms(1000);
    Stepturn(120,0);
		
		for(u8 i=12 ; i>0 ; i-- ){
		
		//OLED_ShowString(1,1,"Loading  ...");
		//OLED_ShowNum(1,8,i,2);
		SysTick_Delay_ms(500);
	  	    dataA[i]=LIghtA_Intensity();
		SysTick_Delay_ms(100);
			dataB[i]=LIghtB_Intensity();
		SysTick_Delay_ms(100);
			dataC[i]=LIghtC_Intensity();
		SysTick_Delay_ms(100);
			dataD[i]=LIghtD_Intensity();
		SysTick_Delay_ms(100);
			dataE[i]=LIghtE_Intensity();
		SysTick_Delay_ms(100);
			dataF[i]=LIghtF_Intensity();
		SysTick_Delay_ms(100);
			dataG[i]=LIghtG_Intensity();
		SysTick_Delay_ms(100);
			dataH[i]=LIghtH_Intensity();
		SysTick_Delay_ms(500);
	Stepturn(1200,0);
		}
		
		SysTick_Delay_ms(1000);
	Stepturn(4600,0);//4133
	}
void sampling_2(void)
{		
	BH1750Init();
		SysTick_Delay_ms(1000);
	Stepturn(21000,1);//  18533
  	    SysTick_Delay_ms(1000);
    Stepturn(120,0);
		
		for(u8 i=12 ; i>0 ; i-- ){
		
		//OLED_ShowString(1,1,"Loading  ...");
		//OLED_ShowNum(1,8,i,2);
		SysTick_Delay_ms(500);
	  	    dataA2[i]=LIghtA_Intensity();
		SysTick_Delay_ms(100);
			dataB2[i]=LIghtB_Intensity();
		SysTick_Delay_ms(100);
			dataC2[i]=LIghtC_Intensity();
		SysTick_Delay_ms(100);
			dataD2[i]=LIghtD_Intensity();
		SysTick_Delay_ms(100);
			dataE2[i]=LIghtE_Intensity();
		SysTick_Delay_ms(100);
			dataF2[i]=LIghtF_Intensity();
		SysTick_Delay_ms(100);
			dataG2[i]=LIghtG_Intensity();
		SysTick_Delay_ms(100);
			dataH2[i]=LIghtH_Intensity();
		SysTick_Delay_ms(500);
	Stepturn(1200,0);
		}
		
		SysTick_Delay_ms(1000);
	Stepturn(4600,0);//4133
	}
	
void printf_T(void)
{
	for(u8 i=1 ; i<13 ; i++ ){
		TA[i]=100*dataA2[i]/dataA[i];
		TB[i]=100*dataB2[i]/dataB[i];
		TC[i]=100*dataC2[i]/dataC[i];
		TD[i]=100*dataD2[i]/dataD[i];
		TE[i]=100*dataE2[i]/dataE[i];
		TF[i]=100*dataF2[i]/dataF[i];
		TG[i]=100*dataG2[i]/dataG[i];
		TH[i]=100*dataH2[i]/dataH[i];
		

	}
	    //printf("A1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",TA[1],TA[2],TA[3],TA[4],TA[5],TA[6],TA[7],TA[8],TA[9],TA[10],TA[11],TA[12]);
		//printf("B1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",TB[1],TB[2],TB[3],TB[4],TB[5],TB[6],TB[7],TB[8],TB[9],TB[10],TB[11],TB[12]);
		printf("C1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",TC[1],TC[2],TC[3],TC[4],TC[5],TC[6],TC[7],TC[8],TC[9],TC[10],TC[11],TC[12]);
		printf("D1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",TD[1],TD[2],TD[3],TD[4],TD[5],TD[6],TD[7],TD[8],TD[9],TD[10],TD[11],TD[12]);
		printf("E1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",TE[1],TE[2],TE[3],TE[4],TE[5],TE[6],TE[7],TE[8],TE[9],TE[10],TE[11],TE[12]);
		printf("F1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",TF[1],TF[2],TF[3],TF[4],TF[5],TF[6],TF[7],TF[8],TF[9],TF[10],TF[11],TF[12]);
	    //printf("G1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",TG[1],TG[2],TG[3],TG[4],TG[5],TG[6],TG[7],TG[8],TG[9],TG[10],TG[11],TG[12]);
		//printf("H1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",TH[1],TH[2],TH[3],TH[4],TH[5],TH[6],TH[7],TH[8],TH[9],TH[10],TH[11],TH[12]);

}

void printf_OD(void)
{
	for(u8 i=1 ; i<13 ; i++ ){
		TA[i]=100*dataA2[i]/dataA[i];
		TB[i]=100*dataB2[i]/dataB[i];
		TC[i]=100*dataC2[i]/dataC[i];
		TD[i]=100*dataD2[i]/dataD[i];
		TE[i]=100*dataE2[i]/dataE[i];
		TF[i]=100*dataF2[i]/dataF[i];
		TG[i]=100*dataG2[i]/dataG[i];
		TH[i]=100*dataH2[i]/dataH[i];
		
		ODA[i]=-log10(TA[i]/100);
		ODB[i]=-log10(TB[i]/100);
		ODC[i]=-log10(TC[i]/100);
		ODD[i]=-log10(TD[i]/100);
		ODE[i]=-log10(TE[i]/100);
		ODF[i]=-log10(TF[i]/100);
		ODG[i]=-log10(TG[i]/100);
		ODH[i]=-log10(TH[i]/100);
		
		
	}
	    //printf("ODA1-12:%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\r\n",ODA[1],ODA[2],ODA[3],ODA[4],ODA[5],ODA[6],ODA[7],ODA[8],ODA[9],ODA[10],ODA[11],ODA[12]);
		//printf("ODB1-12:%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\r\n",ODB[1],ODB[2],ODB[3],ODB[4],ODB[5],ODB[6],ODB[7],ODB[8],ODB[9],ODB[10],ODB[11],ODB[12]);
		printf("ODC1-12:%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\r\n",ODC[1],ODC[2],ODC[3],ODC[4],ODC[5],ODC[6],ODC[7],ODC[8],ODC[9],ODC[10],ODC[11],ODC[12]);
		printf("ODD1-12:%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\r\n",ODD[1],ODD[2],ODD[3],ODD[4],ODD[5],ODD[6],ODD[7],ODD[8],ODD[9],ODD[10],ODD[11],ODD[12]);
		printf("ODE1-12:%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\r\n",ODE[1],ODE[2],ODE[3],ODE[4],ODE[5],ODE[6],ODE[7],ODE[8],ODE[9],ODE[10],ODE[11],ODE[12]);
		printf("ODF1-12:%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\r\n",ODF[1],ODF[2],ODF[3],ODF[4],ODF[5],ODF[6],ODF[7],ODF[8],ODF[9],ODF[10],ODF[11],ODF[12]);
	    //printf("ODG1-12:%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\r\n",ODG[1],ODG[2],ODG[3],ODG[4],ODG[5],ODG[6],ODG[7],ODG[8],ODG[9],ODG[10],ODG[11],ODG[12]);
		//printf("ODH1-12:%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\r\n",ODH[1],ODH[2],ODH[3],ODH[4],ODH[5],ODH[6],ODH[7],ODH[8],ODH[9],ODH[10],ODH[11],ODH[12]);

}

void printf_1(void)
	{
		//printf("透光率12：%f %%\r\n",dataA[10]/dataA[4]*100);
		
		//printf("吸光度12：%f\r\n",log10(dataA[4]/dataA[10]));
		//printf("A1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataA[1],dataA[2],dataA[3],dataA[4],dataA[5],dataA[6],dataA[7],dataA[8],dataA[9],dataA[10],dataA[11],dataA[12]);
		//printf("B1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataB[1],dataB[2],dataB[3],dataB[4],dataB[5],dataB[6],dataB[7],dataB[8],dataB[9],dataB[10],dataB[11],dataB[12]);
		printf("C1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataC[1],dataC[2],dataC[3],dataC[4],dataC[5],dataC[6],dataC[7],dataC[8],dataC[9],dataC[10],dataC[11],dataC[12]);
		printf("D1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataD[1],dataD[2],dataD[3],dataD[4],dataD[5],dataD[6],dataD[7],dataD[8],dataD[9],dataD[10],dataD[11],dataD[12]);
		printf("E1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataE[1],dataE[2],dataE[3],dataE[4],dataE[5],dataE[6],dataE[7],dataE[8],dataE[9],dataE[10],dataE[11],dataE[12]);
		printf("F1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataF[1],dataF[2],dataF[3],dataF[4],dataF[5],dataF[6],dataF[7],dataF[8],dataF[9],dataF[10],dataF[11],dataF[12]);
	    //printf("G1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataG[1],dataG[2],dataG[3],dataG[4],dataG[5],dataG[6],dataG[7],dataG[8],dataG[9],dataG[10],dataG[11],dataG[12]);
		//printf("H1-12:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataH[1],dataH[2],dataH[3],dataH[4],dataH[5],dataH[6],dataH[7],dataH[8],dataH[9],dataH[10],dataH[11],dataH[12]);

	}
	void printf_2(void)
	{
		//printf("透光率12：%f %%\r\n",dataA[10]/dataA[4]*100);
		
		//printf("吸光度12：%f\r\n",log10(dataA[4]/dataA[10]));
		//printf("A:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataA2[1],dataA2[2],dataA2[3],dataA2[4],dataA2[5],dataA2[6],dataA2[7],dataA2[8],dataA2[9],dataA2[10],dataA2[11],dataA2[12]);
		//printf("B:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataB2[1],dataB2[2],dataB2[3],dataB2[4],dataB2[5],dataB2[6],dataB2[7],dataB2[8],dataB2[9],dataB2[10],dataB2[11],dataB2[12]);
		printf("C:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataC2[1],dataC2[2],dataC2[3],dataC2[4],dataC2[5],dataC2[6],dataC2[7],dataC2[8],dataC2[9],dataC2[10],dataC2[11],dataC2[12]);
		printf("D:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataD2[1],dataD2[2],dataD2[3],dataD2[4],dataD2[5],dataD2[6],dataD2[7],dataD2[8],dataD2[9],dataD2[10],dataD2[11],dataD2[12]);
		printf("E:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataE2[1],dataE2[2],dataE2[3],dataE2[4],dataE2[5],dataE2[6],dataE2[7],dataE2[8],dataE2[9],dataE2[10],dataE2[11],dataE2[12]);
		printf("F:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataF2[1],dataF2[2],dataF2[3],dataF2[4],dataF2[5],dataF2[6],dataF2[7],dataF2[8],dataF2[9],dataF2[10],dataF2[11],dataF2[12]);
        //printf("G:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataG2[1],dataG2[2],dataG2[3],dataG2[4],dataG2[5],dataG2[6],dataG2[7],dataG2[8],dataG2[9],dataG2[10],dataG2[11],dataG2[12]);
		//printf("H:%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\r\n",dataH2[1],dataH2[2],dataH2[3],dataH2[4],dataH2[5],dataH2[6],dataH2[7],dataH2[8],dataH2[9],dataH2[10],dataH2[11],dataH2[12]);
		
	}
	void test(void)
	{
		if(i2cA_CheckDevice(BH1750A_Addr)==0)
  printf("BH1750A设备检测成功\r\n");
  else printf("BH1750A设备检测失败\r\n");
	BH1750A_Init();
	  	if(i2cB_CheckDevice(BH1750B_Addr)==0)
  printf("BH1750B设备检测成功\r\n");
  else printf("BH1750B设备检测失败\r\n");
	BH1750B_Init();	
		if(i2cC_CheckDevice(BH1750C_Addr)==0)
  printf("BH1750C设备检测成功\r\n");
  else printf("BH1750C设备检测失败\r\n");
	BH1750C_Init();
		if(i2cD_CheckDevice(BH1750D_Addr)==0)
    printf("BH1750D设备检测成功\r\n");
    else printf("BH1750D设备检测失败\r\n");
	  BH1750D_Init();
		if(i2cE_CheckDevice(BH1750E_Addr)==0)
  printf("BH1750E设备检测成功\r\n");
  else printf("BH1750E设备检测失败\r\n");
	BH1750E_Init();
		if(i2cF_CheckDevice(BH1750F_Addr)==0)
  printf("BH1750F设备检测成功\r\n");
  else printf("BH1750F设备检测失败\r\n");
	BH1750F_Init();
		if(i2cG_CheckDevice(BH1750G_Addr)==0)
  printf("BH1750G设备检测成功\r\n");
  else printf("BH1750G设备检测失败\r\n");
	BH1750G_Init();
		if(i2cH_CheckDevice(BH1750H_Addr)==0)
  printf("BH1750H设备检测成功\r\n");
  else printf("BH1750H设备检测失败\r\n");
	BH1750H_Init();
	  printf("设备准备完毕\r\n");
		printf("请进行下一步操作\r\n");
	}
	
	void in(void)
{		
	Stepturn(2400,1);
	
}
	void out(void)
{		
	Stepturn(2400,0);
	
}
	int main(void)

{
	//for(u8 i=1; i<5; i++){
	//OLED_Init();
	
	//Encoder_Init();
	LED_init();
	InitSTEP();	
    
	USART_Config();
	


		while(1)
		{
			int c;
 
        printf("请选择操作:\n");
			printf(" 0:测试传感器\n 1:参照板采样 2:待测板采样 \n 3:参照版数据输出 4:待测板数据输出 \n 5:透光率输出 6:吸光度输出 \n 7:存板 8:退板 \n9:开灯 10:关灯 \n");
    
	    scanf("%d\n",&c);
			
		printf("%d\n",c)	;
    switch(c){
		
		 case 0 :
		 test();
	break;
		 
         case 1 :
	     sampling_1();
    break;
		 
		 case 2 :
		 sampling_2();
	break;
		 
		 case 3 :
		 printf_1();
	break;
		 
		 case 4 :
		 printf_2();
    break;	
		 
		 case 5 :
		 printf_T();
	break;
		 
		 case 6 :
		 printf_OD();
    break;	

		 case 7 :
		 in();
    break;		
		 
		 case 8 :
		 out();
    break;	
		 
		 case 9 :
		 LED_on();
    break;		
		 
		 case 10 :
		 LED_off();
    break;	
		 
		 default :
		printf("无效操作");
	break;
				
			}
			
		}
		
		
		//OLED_Clear();
	}

	
	
	//}
	 //while(1){
		
	/*while(1){
		
		page -= Encoder_Get();
		if(page<1)			page=1;
		OLED_ShowString(1,12," PG");
		OLED_ShowNum(1, 15, page, 1);
		
	 
		
		if(page ==1 ){	
	
		OLED_ShowFNum(1, 1, data[1], 5,1); 
		
		OLED_ShowFNum(2, 1, data[2], 5,1); 
		
		OLED_ShowFNum(3, 1, data[3], 5,1); 
		
		OLED_ShowFNum(4, 1, data[4], 5,1); 
		OLED_ShowString(1,8,"Lx");		
		OLED_ShowString(2,8,"Lx");		
		OLED_ShowString(3,8,"Lx");		
		OLED_ShowString(4,8,"Lx");}
		
		if(page==2){
	  
		OLED_ShowFNum(1, 1, data[5], 5,1); 
		
		OLED_ShowFNum(2, 1, data[6], 5,1); 
		
		OLED_ShowFNum(3, 1, data[7], 5,1); 
		
		OLED_ShowFNum(4, 1, data[8], 5,1); 
		OLED_ShowString(1,8,"Lx");		
		OLED_ShowString(2,8,"Lx");		
		OLED_ShowString(3,8,"Lx");		
		OLED_ShowString(4,8,"Lx");}
		
		if(page ==3 ){	
	
		OLED_ShowFNum(1, 1, data[9], 5,1); 
		
		OLED_ShowFNum(2, 1, data[10], 5,1); 
		
		OLED_ShowFNum(3, 1, data[11], 5,1); 
		
		OLED_ShowFNum(4, 1, data[12], 5,1); 
		OLED_ShowString(1,8,"Lx");		
		OLED_ShowString(2,8,"Lx");		
		OLED_ShowString(3,8,"Lx");		
		OLED_ShowString(4,8,"Lx");}
    if(page==4){
			
			break;}
	}
	while(1)
	{
		OLED_ShowFNum(1, 3, LIghtA_Intensity(), 5,1); 
		OLED_ShowString(1,1,"L:");OLED_ShowString(1,10,"Lx");
		
		OLED_ShowFNum(2, 3, data[10]/data[4]*100, 2,4); 
		OLED_ShowString(2,1,"T:");OLED_ShowChar(2,10,'%');
		
		OLED_ShowFNum(3, 3, log10(data[4]/data[10]), 1,5); 
		OLED_ShowString(3,1,"A:");
		
		OLED_ShowString(4,1,"12   data");*/
		
		
	/*	printf("a光强：%f lx\r\n",LIghtA_Intensity());
		SysTick_Delay_ms(1000);
		printf("b光强：%f lx\r\n",LIghtB_Intensity());
		SysTick_Delay_ms(1000);
		printf("c光强：%f lx\r\n",LIghtC_Intensity());
		SysTick_Delay_ms(1000);
		printf("d光强：%f lx\r\n",LIghtD_Intensity());
		SysTick_Delay_ms(1000);
		printf("e光强：%f lx\r\n",LIghtE_Intensity());
		SysTick_Delay_ms(1000);
		printf("f光强：%f lx\r\n",LIghtF_Intensity());
		SysTick_Delay_ms(1000);
		printf("g光强：%f lx\r\n",LIghtG_Intensity());
		SysTick_Delay_ms(1000);
		printf("h光强：%f lx\r\n",LIghtH_Intensity());*/
		
		
		/*printf("透光率12：%f %%\r\n",data[10]/data[4]*100);
		
		printf("吸光度12：%f\r\n",log10(data[4]/data[10]));
		
		page -= Encoder_Get();
		if(page<1||page>4)			page=1;
		OLED_ShowString(1,12,"PG");
		OLED_ShowNum(1, 15, page, 1);
		SysTick_Delay_ms(3000);
		if(page==1|page==2|page==3){
			OLED_Clear();
			break;}
	}	
}
*/
	// }
 


