#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_AFRL (*((int *)0x40020820))

//UART1 Addresses	
#define UART6_CR1 (*((int *)0x4001140C))
#define UART6_CR2 (*((int *)0x40011410))
#define UART6_CR3 (*((int *)0x40011414))
#define UART6_SR (*((int *)0x40011400))
#define UART6_DR (*((int *)0x40011404))
#define UART6_BRR (*((int *)0x40011408))
	
void UART6_MUX_init()
{
	RCC_AHB1ENR |= 0x4;//set bit 0,1 to enable clock for port A and port B
	while(!(RCC_AHB1ENR&0x4))//wait until clock is set
	{
		;
	}
	GPIOC_MODER &= 0xFFFF0FFF;//clear 15-12 bits
	GPIOC_MODER |= 0x0000A000;//load '1010' into 15-12 bit fiels ,PC6 & PC7 as Alternative function mode 
	GPIOC_AFRL &= 0x00FFFFFF;//clear AFRL6,AFRL7
	GPIOC_AFRL |= 0x88000000;//load '1000' into both AFRH6,AFRH7 to set as UART1
}

void KM_UART6_init_cofig()
{
	RCC_APB2ENR |= 0x1<<5;//Enable clock for UART6
	while(!(RCC_APB2ENR&0x1<<5));//wail until clock is set
	UART6_CR1 |= 0x1<<13;//Enable UART6
	UART6_CR1 |= 0x1<<2;//Enable Receiver
	UART6_CR1 |= 0x1<<3;//Enable Transmitter
	UART6_BRR |= 0X87;//load 115200 bps 
}

void KM_UART6_outchar(unsigned char data)
{
	while(!(UART6_SR&0x1<<7))//wait until Transmitter empty
	{
		;
	}
	UART6_DR = data;//load data into data register
}

unsigned char KM_UART6_inchar(void)
{
		while(!(UART6_SR&0x1<<5))//wait until Receiver full
		{
			;//return data
		}
	return (UART6_DR&0xFF);
}

void KM_UART6_OutString(char str[])
{
	int i=0;
	for(;str[i];i++)
	{
		KM_UART6_outchar	(str[i]);//character by chararcter sending data
	}
}

