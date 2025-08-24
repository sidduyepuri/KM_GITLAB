#include "SysTickTimer.h"
#include "LCD_code.h"
int main()
{
	//phase 1: Initialization phase
	RCC_init();
	LCD_config();
	STK_Timer_init();
	KM_LCD_init();
	//operation phase
	KM_LCD_write_data(0x80);//command for cursor moves to first line	
	KM_LCD_String("KERNEL MASTERS");
	KM_LCD_write_data(0xC0);//command for cursor moves to second line
	KM_LCD_String("GLOBAL INSTITUTE");
	return 0;
}

