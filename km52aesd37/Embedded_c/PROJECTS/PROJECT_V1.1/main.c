#include "SysTickTimer.h"
#include "lcd.h"
#include "i2c.h"
#include "adc1.h"
#include "UART6.h"
#include "WiFi.h"
#include "Time_set.h"
unsigned char rtc_receive[20];

void Task1_ReadRTC_WriteLCD_1Sec(void);
int Task2_ReadLM35_WriteLCD_5Sec(void);
int lm35_data,LM35_flag;
int Resp,i,x;

unsigned char T_date[20];
char str1[20];
unsigned char EEPROME_write[20],EEPROME_read[20];

int main()
{
	
	RCC_init();
	ADC_MUX_init();
	UART6_MUX_init();
	LCD_config();
	KM_ADC_init();
	SW_init_config();
	KM_UART6_init_cofig();
	KM_I2C1_Init();
	STK_Timer_init();
	KM_LCD_init();
	KM_I2C1_Config();
	KM_I2C_Mem_Read(0x68,0x00,0x01,T_date,7);
	KM_LCD_write_cmd(0x01);
	KM_LCD_write_cmd(0x82);
	KM_LCD_String("WELCOME TO");
	KM_LCD_write_cmd(0xC1);
	KM_LCD_String("KERNEL MASTERS");
	x=167000*3;
	while(x--)
	{
		Task5_SWMS_Config(T_date);
	}
	KM_LCD_write_cmd(0x01);
	KM_LCD_write_cmd(0x82);
	KM_LCD_String("WELCOME TO");
	KM_LCD_write_cmd(0xC1);
	KM_LCD_String("KERNEL MASTERS");
	ESP8266();
	KM_I2C_Mem_Write(0x68,0x00,0x01,T_date,7);
	KM_I2C_Mem_Read(0x50,0x00,0x08,EEPROME_read,8);
	KM_LCD_write_cmd(0x01);
	while(1)
	{
		//TASK-1
		Task1_ReadRTC_WriteLCD_1Sec();
		KM_mdelay(100);
		//TASK-2
		lm35_data=Task2_ReadLM35_WriteLCD_5Sec();
		LM35_flag=1;
		KM_LCD_write_cmd(0x8A);
		str1[0]=(lm35_data/10)+48;
		str1[1]=(lm35_data%10)+48;
		KM_LCD_String("T:");
		str1[2]=0xdf;
		str1[3]=0x43;
		KM_LCD_String(str1);
		//TASK-3
		if(LM35_flag==1)
		{
			Resp=Task3_WiFi_Tx(lm35_data);
			if(Resp==-1){
				KM_LCD_write_cmd(0xCA);
				KM_LCD_String("ERROR");
			}
			else{
				KM_LCD_write_cmd(0xCA);
				KM_LCD_String(" OK  ");
			}
		}
		//TASK-4
		if(Task4_Check_InternetStatus()==-1)
		{
			KM_I2C_Mem_Read(0x68,0x00,0x01,rtc_receive,7);
			EEPROME_write[0] = lm35_data;
			for(i=0;i<8;i++)
			{
				EEPROME_write[i+1] = rtc_receive[i];
			}
			KM_I2C_Mem_Write(0x50,0x00,0x08,EEPROME_write,8);
		}
	}
	return 0;
}

