#include "UART6.h"
#include "SysTickTimer.h"

char Rxbuff[500];
int Check_Wifi_OK_Response()
{
	int i;
	for(i=0;i<200;i++)
		{
			Rxbuff[i] = KM_UART6_inchar();//Receiving data from outside data
			if((Rxbuff[i]=='K')&&(Rxbuff[i-1]=='O'))
			{
				return 0;
			}
		}
		return 1;
}

void ESP8266()
{
	//ESP8266 Initalization	
	KM_UART6_OutString("AT\r\n");
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(10);
	
	//Step2: ESP8266_SetWifiMode
	KM_UART6_OutString("AT+CWMODE=3\r\n");//set MODE as 3
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(10);
	
	//Step3: ESP8266_JoinAccessPoint
	KM_UART6_OutString("AT+CWJAP=\"KM-2.4G\",\"9963111084\"\r\n");//connecting to wifi
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(10);
	
	//Step4: ESP8266_GetIPAddress
	KM_UART6_OutString("AT+CIFSR\r\n");
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(10);
	
	//Step5: ESP8266_SetConnectionMux
	KM_UART6_OutString("AT+CIPMUX=0\r\n");
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(10);
	
	//Step7: ESP8266_SetDataTransmissionMode
	KM_UART6_OutString("AT+CIPMODE=0\r\n");
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(100);
}

