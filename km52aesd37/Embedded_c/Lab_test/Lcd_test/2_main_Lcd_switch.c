#include "LCD_code.h"
#include "SysTickTimer.h"
#include "Ent_switch.h"
int main()
{
	//phase 1: Initialization phase
	RCC_init();
	Enter_SW_config();
	LCD_config();
	Ent_SW_init();
	STK_Timer_init();
	KM_LCD_init();
	//operation phase
	
		while(1)
		{
			for(i=0;i<=5;i++){
				KM_mdelay(1000);
			}
			if(count==1){
				count=0;
				KM_LCD_write_cmd(0x01);
			KM_LCD_String("INDIA");
			}
			if(count==2){
			count=0;
			KM_LCD_write_cmd(0x01);
			KM_LCD_String("IS");
			}
			if(count==3){
			count=0;
			KM_LCD_write_cmd(0x01);
			KM_LCD_String("A");
			}
			if(count==4){
			count=0;
			KM_LCD_write_cmd(0x01);
			KM_LCD_String("GREAT");
			}
			if(count==5){
			count=0;
			KM_LCD_write_cmd(0x01);
			KM_LCD_String("COUNTRY");
			}
	}
	return 0;
}


void EXTI15_10_IRQHandler(void)
{
	if(EXTI_PR&0x1<<10)
	{
	
		count++;
		EXTI_PR |= 0x1<<10;
		KM_mdelay(1000);
	}	
}

