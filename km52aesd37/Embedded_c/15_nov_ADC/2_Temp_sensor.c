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
	RCC_AHB1ENR |= 0x1<<2;//set 2nd position to Enable clock for GPIOC 
	GPIOC_MODER &= ~(0xFFFFFFFC);//clear 1-0 position
	GPIOC_MODER |= (0x00000003);//load 11 into 1-0 bit positions to set Analog mode
}
void KM_ADC_init()
{
	RCC_APB2ENR |= 0x1<<8;//set 8th bit to Enable clock for ADC1
//	ADC_SQR1 &= ~(0xFF0FFFFF);//clear 23-20 bit positions
//	ADC_SQR1 |= (0x00100000);	//load '0001' into 23-20 bit position to set length is 2channels
	ADC_SQR3 |= 0x0A;//load '0A' to set channel10
	ADC_CR1 |= 0x1<<5;//set '5th' bit position to enable EOCIS interrupt
	ADC_CR2 |= 0x1;//set 0th bit position to Enable ADON
}

int main()
{
	MUX_init();
	KM_ADC_init();
	STK_Timer_init();
	NVIC_ISER0 |= 0x1<<18;//connect ADC1 interrupt to NVIC
	while(1)
	{
		ADC_CR2 |= 0x1<<30;//set 30th bit for software trigger
		KM_mdelay(500);
	}
}

void ADC_IRQHandler(void)
{
	TEMP_value=ADC_DR;//assigning data reg value into global variable
	TEMP_value=(TEMP_value*3000)/(4096*10);//formula for temperature calculation
}

