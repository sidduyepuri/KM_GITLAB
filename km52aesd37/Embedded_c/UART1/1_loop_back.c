#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
#define GPIOA_MODER (*((int *)0x40020000))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOA_AFRH (*((int *)0x40020024))
//UART1 Addresses	
#define UART1_CR1 (*((int *)0x4001100C))
#define UART1_CR2 (*((int *)0x40011010))
#define UART1_CR3 (*((int *)0x40011014))
#define UART1_SR (*((int *)0x40011000))
#define UART1_DR (*((int *)0x40011004))
#define UART1_BRR (*((int *)0x40011008))
char ch;

void UART1_MUX_init()
{
	RCC_AHB1ENR |= 0x3;//set bit 0,1 to enable clock for port A and port B
	while(!((RCC_AHB1ENR&0x1)&&(RCC_AHB1ENR&0x2)))//wait until clock is set
	{
		;
	}
	GPIOA_MODER &= 0xFFC3FFFF;//clear 21-18 bits
	GPIOA_MODER |= 0x00280000;//load '1010' into 21-18 bit fiels ,PA9 & PA10 as Alternative function mode 
	GPIOA_AFRH	&= 0xFFFFF00F;//clear AFRH9,AFRH10
	GPIOA_AFRH	|= 0x00000770;//load '0111' into both AFRH9,AFRH10 to set as UART1
}

void KM_UART_init_cofig()
{
	RCC_APB2ENR |= 0x1<<4;//Enable clock for UART1
	while(!(RCC_APB2ENR&0x10));//wail until clock is set
	UART1_CR1 |= 0x1<<13;//Enable UART1
	UART1_CR1 |= 0x1<<2;//Enable Receiver
	UART1_CR1 |= 0x1<<3;//Enable Transmitter
	UART1_BRR |= 0X683;//load 9600 bps 
}
void KM_UART1_outchar(unsigned char data)
{
	while(!(UART1_SR&0x1<<7))//wait until Transmitter empty
	{
		;
	}
	UART1_DR = data;//load data into data register
}

unsigned char KM_UART1_inchar(void)
{
	while(!(UART1_SR&0x1<<5))//wait until Receiver full
	{
		;
	}
	return (UART1_DR&0xFF);//return data
}

int main()
{
	UART1_MUX_init();
	KM_UART_init_cofig();
	while(1)
	{
		KM_UART1_outchar('J');//Transer 'J' char to outside device
		ch = KM_UART1_inchar();//Receiving data from outside data
//		ch++;
	}
}

