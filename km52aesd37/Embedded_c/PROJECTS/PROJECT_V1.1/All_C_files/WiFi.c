#include "UART6.h"
#include "SysTickTimer.h"
#include <stdio.h>
#include <string.h>

int j;
char Rxbuff[500];
char Fetch[50];
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
			if((Rxbuff[i]=='5')&&(Rxbuff[i-1]==':')&&(Rxbuff[i-2]=='S')&&(Rxbuff[i-3]=='U')&&(Rxbuff[i-4]=='T')&&(Rxbuff[i-5]=='A')&&(Rxbuff[i-6]=='T')&&(Rxbuff[i-7]=='S'))
			{
				return -1;
			}
			if((Rxbuff[i]=='R')&&(Rxbuff[i-1]=='O')&&(Rxbuff[i-2]=='R')&&(Rxbuff[i-3]=='R')&&(Rxbuff[i-4]=='E'))
				return -1;
			if((Rxbuff[i]=='L')&&(Rxbuff[i-1]=='I')&&(Rxbuff[i-2]=='A')&&(Rxbuff[i-3]=='F'))
				return -1;
		}
		return 1;
}

void ESP8266()
{
	
	KM_UART6_OutString("AT\r\n");
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(10);
	
	KM_UART6_OutString("AT+CWMODE=3\r\n");
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(10);
	
	KM_UART6_OutString("AT+CWJAP=\"KM-2.4G\",\"9963111084\"\r\n");
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(10);
	
	KM_UART6_OutString("AT+CIFSR\r\n");
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(10);
	
	KM_UART6_OutString("AT+CIPMUX=0\r\n");
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(10);
	
	KM_UART6_OutString("AT+CIPMODE=0\r\n");
	if(Check_Wifi_OK_Response()!=0)
	{
		;
	}
	KM_mdelay(100);
}

int Task3_WiFi_Tx(int TEMP)
{
		KM_UART6_OutString("AT+CIPSTATUS\r\n");
		j=Check_Wifi_OK_Response();
		if(j!=0)
		{
			return -1;
		}

		KM_UART6_OutString("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
		j=Check_Wifi_OK_Response();
		if(j!=0)
		{
			return -1;
		}

		sprintf(Fetch,"GET /page.php?temp=%d&hum=87&dev=37\r\n\r\n",TEMP);
		KM_UART6_OutString("AT+CIPSEND=40\r\n");
		j=Check_Wifi_OK_Response();
		if(j!=0)
		{
			return -1;
		}
		KM_UART6_OutString(Fetch);
		KM_UART6_OutString(Fetch);
		if(Check_Wifi_OK_Response()!=0)
		{
			return -1;
		}
		TEMP=0;
}

int Task4_Check_InternetStatus(void)
{
	KM_UART6_OutString("AT+CIPSTATUS\r\n");//Transer 'J' char to outside device
		j=Check_Wifi_OK_Response();
		if(j!=0)
		{
			return -1;
		}
		return 0;
}

