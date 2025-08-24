/*2) Write an Embedded C program to initialize ADC Scan mode.
Using regular channel software trigger samples ADC channel 10 (Temperature sensor) and 11 (potentiometer) and
stores the result to a global variables that can be accessed with the ST-Link Debugger.
using interrupt method.		*/
#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
#define GPIOC_MODER (*((int *)0x40020800))

#define ADC_CR1 (*((int *)0x40012004))
#define ADC_CR2 (*((int *)0x40012008))
#define ADC_SQR1 (*((int *)0x4001202C))
#define ADC_SQR3 (*((int *)0x40012034))
#define ADC_SR (*((int *)0x40012000))
#define ADC_DR (*((int *)0x4001204C))


#define STK_CTRL (*((int *)0xE000E010))
#define STK_LOAD (*((int *)0xE000E014))
#define STK_VAL (*((int *)0xE000E018))
#define NVIC_ISER0 (*((int *)0xE000E100))
#include "LCD_temp.h"

int TEMP_value=0;
char str[10];

//System tick timer initialization
void 	STK_Timer_init()
{
	STK_CTRL |= 0X5;//write '101' bit fiels 0,1,2 to enable,
	STK_VAL = 0X578;//write G.V to STK_VAL
}

void KM_mdelay(int m)
{
	STK_LOAD = m*16000;
	while(!(STK_CTRL&0x1<<16))
	{
		;
	}
}


void MUX_init()
{
	RCC_AHB1ENR |= 0x1<<2;//Enable clock for Port-C
	GPIOC_MODER &= ~(0xFFFFFFFC);//clear 1-0 bit fields
	GPIOC_MODER |= (0x00000003);//load '11' into 1-0 bit fields to set analog mode
}
void KM_ADC_init()
{
	RCC_APB2ENR |= 0x1<<8;//Enable clock for ADC1
	ADC_SQR3 |= 0x0A;//load channel10 into SQ1
	ADC_CR1 |= 0x1<<5;//Enable EOCIE
	ADC_CR2 |= 0x1;//Enable ADON
}
void KM_ADC_read()
{
	ADC_CR2 |= 0x1<<30;//set 30th bit for software trigger
	KM_mdelay(500);
}
int main()
{
	MUX_init();
	RCC_init();
	LCD_config();
	KM_ADC_init();
	STK_Timer_init();
	KM_LCD_init();
	NVIC_ISER0 |= 0x1<<18;//Enable 18th bit for ADC interrupt
	while(1)
	{
		KM_ADC_read();
	}
}

void ADC_IRQHandler(void)
{
	int i=0;
	TEMP_value=ADC_DR;
	TEMP_value=(TEMP_value*3000)/(4096*10);
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
	KM_LCD_write_cmd(0x01);
	KM_LCD_String(str);
	KM_mdelay(350);
}

