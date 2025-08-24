//RCC
#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))

#define GPIOC_MODER (*((int *)0x40020800))

//ADC
#define ADC_CR1 (*((int *)0x40012004))
#define ADC_CR2 (*((int *)0x40012008))
#define ADC_SQR1 (*((int *)0x4001202C))
#define ADC_SQR3 (*((int *)0x40012034))
#define ADC_SR (*((int *)0x40012000))

//SYSTICKTIMER
#define STK_CTRL (*((int *)0xE000E010))
#define STK_LOAD (*((int *)0xE000E014))
#define STK_VAL (*((int *)0xE000E018))

#define NVIC_ISER0 (*((int *)0xE000E100))

#include "lcd.h"
#include "SysTickTimer.h"
#include "adc1.h"

int value=0;

void MUX_init()
{
	GPIOC_MODER &= (0xFFFFFFFC);//clear 0,1 bit fields
	GPIOC_MODER |= (0x00000003);//load '11' into 0,1 bit fields to set as Analog mode
}
void KM_ADC_init()
{
	RCC_APB2ENR |= 0x1<<8;//clock enable for adc1
//	ADC_SQR1 &= ~(0xFF0FFFFF);	
//	ADC_SQR1 |= (0x00100000);	
	ADC_SQR3 |= 0x0A;//load '1010' into ADC_SQR3 to set as channel10-lm35
	ADC_CR1 |= 0x1<<5;//enable EOCIE bit for interrupt generation at end of conversion
	ADC_CR2 |= 0x1;//enable ADON
	NVIC_ISER0 |= 0x1<<18;//Enable ISER for ADC
}
void KM_ADC_read()
{
	ADC_CR2 |= 0x1<<30;//enable 30th bit for software triggering
	KM_mdelay(500);
}


