#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
#define GPIOC_MODER (*((int *)0x40020800))

#define ADC_CR1 (*((int *)0x40012004))
#define ADC_CR2 (*((int *)0x40012008))
#define ADC_SQR1 (*((int *)0x4001202C))
#define ADC_SQR3 (*((int *)0x40012034))
#define ADC_SR (*((int *)0x40012000))
#define ADC_DR (*((int *)0x4001204C))
int TEMP_value=0;

void ADC_MUX_init()
{
	RCC_AHB1ENR |= 0x1<<2;//set 2nd position to Enable clock for GPIOC 
	GPIOC_MODER &= ~(0xFFFFFFFC);//clear 1-0 position
	GPIOC_MODER |= (0x00000003);//load 11 into 1-0 bit positions to set Analog mode
}
void KM_ADC_init()
{
	RCC_APB2ENR |= 0x1<<8;//set 8th bit to Enable clock for ADC1
	ADC_SQR3 |= 0x0A;//load '0A' to set channel10
	ADC_CR1 |= 0x1<<5;//set '5th' bit position to enable EOCIS interrupt
	ADC_CR2 |= 0x1;//set 0th bit position to Enable ADON
}

int Task2_ReadLM35_WriteLCD_5Sec(void)
{
	ADC_CR2 |= 0x1<<30;
	while(!(ADC_SR&(0x1<<1)));
	TEMP_value=ADC_DR;//assigning data reg value into global variable
	TEMP_value=(TEMP_value*3000)/(4096*10);//formula for temperature calculation
	return TEMP_value;
}

