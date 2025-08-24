/*1) Write an Embedded C program to initialize ADC Scan mode.
Using regular channel software trigger samples ADC channel 11 (potentiometer) and
stores the result to a global variable that can be accessed with the ST-Link Debugger.		*/
//	a).Polling method
#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
#define GPIOC_MODER (*((int *)0x40020800))

#define ADC_CR1 (*((int *)0x40012004))
#define ADC_CR2 (*((int *)0x40012008))
#define ADC_SQR3 (*((int *)0x40012034))
#define ADC_SR (*((int *)0x40012000))
#define ADC_DR (*((int *)0x4001204C))


#define STK_CTRL (*((int *)0xE000E010))
#define STK_LOAD (*((int *)0xE000E014))
#define STK_VAL (*((int *)0xE000E018))
int POT_value=0;

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
	RCC_AHB1ENR |= 0x1<<2;//enable clock for GPIOC
	GPIOC_MODER |= 0x3<<2;//load 11 into 3-2 bit positions for Analog mode
}
void KM_ADC_init()
{
	RCC_APB2ENR |= 0x1<<8;//Enable clock for ADC1
	ADC_SQR3 |= 0x0B;//load '0B' to set channel11
//	ADC_CR2 |= 0x1<<10;
	ADC_CR2 |= 0x1;//set 0th bit position to Enable ADON
}
void KM_ADC_read()
{
	ADC_CR2 |= 0x1<<30;//set 30th bit position for software trigger
	while(!(ADC_SR&0X2))//wait for set ADC_SR bit position 1 EOC
	{
		;
	}
	POT_value=ADC_DR;//assign data reg value into global variable
	KM_mdelay(500);
}
int main()
{
	MUX_init();
	KM_ADC_init();
	STK_Timer_init();
	while(1)
	{
		KM_ADC_read();
	}
}

