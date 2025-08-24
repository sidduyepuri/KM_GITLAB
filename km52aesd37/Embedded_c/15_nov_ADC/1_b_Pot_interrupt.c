/*1) Write an Embedded C program to initialize ADC Scan mode.
Using regular channel software trigger samples ADC channel 11 (potentiometer) and
stores the result to a global variable that can be accessed with the ST-Link Debugger.
 b) interrupt method		*/

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
#define NVIC_ISER0 (*((int *)0xE000E100))

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
	RCC_AHB1ENR |= 0x1<<2;//Enable clock for port_B
	GPIOC_MODER |= 0x3<<2;//load '11' into 3-2 bit fields to change Analog mode
}
void KM_ADC_init()
{
	RCC_APB2ENR |= 0x1<<8;//clock Enable for ADC1
	ADC_SQR3 |= 0x0B;//load '0B' into 5-0 bit fiels set sequence as SQ1
	ADC_CR1 |= 0x1<<5;//Enable EOCIE interrupt 
	//ADC_CR2 |= 0x1<<10;//Enable EOCS for polling method
	ADC_CR2 |= 0x1;//Enable ADON
}
void KM_ADC_read()
{
	ADC_CR2 |= 0x1<<30;//Enable software trigger
	KM_mdelay(500);
}
int main()
{
	MUX_init();
	KM_ADC_init();
	STK_Timer_init();
	NVIC_ISER0 |= 0x1<<18;//set 18th position to Enable ADC1 interrupt
	while(1)
	{
		KM_ADC_read();
	}
}

void ADC_IRQHandler(void)
{
	POT_value=ADC_DR;//assign data reg value into G.V
}


