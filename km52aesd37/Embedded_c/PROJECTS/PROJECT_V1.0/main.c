#include <stdio.h>
#include <string.h>
#include "UART6.h"
#include "WiFi.h"
#include "SysTickTimer.h"
#include "lcd.h"
#include "adc1.h"
int TEMP_value=0;
char Fetch[50];
int temp,hum=87,i;
char str[10];

int main()
{
	UART6_MUX_init();
	RCC_init();
	KM_UART6_init_cofig();
	KM_ADC_init();
	MUX_init();
	LCD_config();
	STK_Timer_init();
	KM_LCD_init();
	ESP8266();
	while(1)
	{
		KM_ADC_read();
		//Step1: ESP8266_GetStatus
		KM_UART6_OutString("AT+CIPSTATUS\r\n");
		if(Check_Wifi_OK_Response()!=0)
		{
			;
		}
		KM_mdelay(1000);

		//Step2: ESP8266_MakeTCPConnection
		KM_UART6_OutString("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
		if(Check_Wifi_OK_Response()!=0)
		{
			;
		}
		KM_mdelay(2000);

			//Step3: ESP8266_SendTcp
			sprintf(Fetch,"GET /page.php?temp=%d&hum=87&dev=37\r\n\r\n",TEMP_value);
			KM_UART6_OutString("AT+CIPSEND=40\r\n");//
			KM_mdelay(500);
			KM_UART6_OutString(Fetch);
			KM_UART6_OutString(Fetch);
			if(Check_Wifi_OK_Response()!=0)
			{
				;
			}
			for(i=0;i<5;i++)
				KM_mdelay(1000);
		}
}

void ADC_IRQHandler(void)
{
	int i=0;
	TEMP_value=ADC_DR;
	TEMP_value=(TEMP_value*3000)/(4096*10);//Temperature calculation formula
	while(i<=1)
	{
		if(i==0){
			str[i]=(TEMP_value/10)+48;
		}
		else if(i==1){
			str[i]=(TEMP_value%10)+48;
		}
		i++;
	}
	KM_LCD_write_cmd(0x01);//clear lcd
	KM_LCD_String(str);
	KM_mdelay(350);
}

