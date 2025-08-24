//RCC 
#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))

//GPIOA
#define GPIOA_MODER (*((int *)0x40020000))
#define GPIOA_AFRH (*((int *)0x40020024))

//GPIOB
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))

//GPIOC	
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_PUPDR (*((int *)0x4002080C))	

//SysTick timer Addresses
#define STK_CTRL (*((int *)0xE000E010))
#define STK_LOAD (*((int *)0xE000E014))
#define STK_VAL (*((int *)0xE000E018))

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
	RCC_AHB1ENR |= 0x7;//set bit 0,1,2 to enable clock for port A,B&C
	while(!((RCC_AHB1ENR&0x1)&&(RCC_AHB1ENR&0x2)&&(RCC_AHB1ENR&0x4)))//wait until clock is set
	{
		;
	}
	GPIOA_MODER &= 0xFFC3FFFF;//clear 21-18 bits
	GPIOA_MODER |= 0x00280000;//load '1010' into 21-18 bit fiels ,PA9 & PA10 as Alternative function mode 
	GPIOA_AFRH &= 0xFFFFF00F;//clear AFRH9,AFRH10
	GPIOA_AFRH |= 0x00000770;//load '0111' into both AFRH9,AFRH10 to set as UART1
}

void RED_GREEN_config(void)
{
	GPIOB_MODER &= 0xC3FFFFFF;//clear 29-24 bits
	GPIOB_MODER |= 0x14000000;//load "01" into 29th-24th bit fields
}

void UP_DW_SW_config(void)
{
	GPIOC_MODER &= 0xFFF0FFFF;//clear 21th & 20th bits
	GPIOC_MODER |= 0x00000000;//load "01" into 21tH-20th bit fields
	GPIOC_PUPDR &= 0xFFF5FFFF;//clear 21th & 20th bits
	GPIOC_PUPDR |= 0x00050000;//load "01" into 21th-20th bit fields
}

void KM_UART_init_cofig()
{
	RCC_APB2ENR |= 0x1<<4;//Enable clock for UART1
	while(!(RCC_APB2ENR&0x10));//wail until clock is set
	UART1_CR1 |= 0x1<<13;//Enable UART1
	UART1_CR1 |= 0x1<<2;//Enable Receiver
	UART1_CR1 |= 0x1<<3;//Enable Transmitter
	UART1_BRR |= 0x683;//load 9600 bps 
}
void KM_UART1_outchar(unsigned char data)
{
	while(!(UART1_SR&0x1<<7))//wait until Transmitter empty
	{
		;
	}
	UART1_DR = data;//load data into data register
}

unsigned char KM_UART1_inchar_TIMEOUT(void)
{
	int x=100;
	while(x--)
	{
		if(UART1_SR&0x1<<5)
		{
			return (UART1_DR&0xFF);
		}
	}
	return -1;
}

//System tick timer initialization
void 	STK_Timer_init()
{
	STK_CTRL |= 0X5;
	STK_VAL = 0X578;
}

void KM_mdelay(int m)
{
	STK_LOAD = m*16000;
	while(!(STK_CTRL&0x1<<16))
	{
		;
	}
}

int main()
{
	//Initialization and configuration phase
	UART1_MUX_init();
	STK_Timer_init();
	RED_GREEN_config();
	UP_DW_SW_config();
	KM_UART_init_cofig();
	
	//set 14th and 13th bit to OFF LED's at the time of RESET
	GPIOB_ODR |= (0x1<<14);
	GPIOB_ODR |= (0x1<<13);
	
	//operation phase
	while(1)
	{
		KM_mdelay(200);
		if(!(GPIOC_IDR&0x1<<8))//check 8th bit position 
		{
			KM_UART1_outchar('R');//Transmit 'R' to the Rayaan board 2
		}
		if(!(GPIOC_IDR&0x1<<9))//check 9th bit position
		{
			KM_UART1_outchar('G');//Transmit 'G' to the Rayaan board 2
		}
		ch=KM_UART1_inchar_TIMEOUT();
		if(ch=='G')//wait for the input
		{
			GPIOB_ODR ^= (0x1<<14);//clear bit position 14 to ON GREEN LED
		}
		if(ch=='R')//wait for the input
		{
			GPIOB_ODR ^= (0x1<<13);//clear bit position 13th to ON RED LED
		}
	}
}

