#include "SysTickTimer.h"
#include "lcd.h"
#include "i2c.h"
char str[20];
unsigned char rtc_data[20];

void Task1_ReadRTC_WriteLCD_1Sec()
{
	
		int i=2,j=4,k=0;
		KM_LCD_write_cmd(0x80);//cursor moves to first line
		KM_I2C_Mem_Read( 0x68, 0x00, 0x01, rtc_data, 7);//Memory read function
		KM_mdelay(500);
		for(;rtc_data[k];k++)
		{
			rtc_data[k]=(rtc_data[k]/16)*10+(rtc_data[k]%16);
		}
		KM_LCD_String(" ");
		while(i>=0)
		{
			
			str[0]=(rtc_data[i]/10)+48;
			str[1]=(rtc_data[i]%10)+48;
			KM_LCD_String(str);
			if(i!=0)
				KM_LCD_String(":");
			i--;
		}
		KM_LCD_write_cmd(0xC0);
		KM_LCD_String(" ");
		while(j<7)
		{
			str[0]=(rtc_data[j]/10)+48;
			str[1]=(rtc_data[j]%10)+48;
			KM_LCD_String(str);
			if(j!=6)
				KM_LCD_String("/");
			j++;
		}
}

