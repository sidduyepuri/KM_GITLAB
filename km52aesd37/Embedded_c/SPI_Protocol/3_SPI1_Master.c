//Experiment 3: Develop Communication between two Raayn MIni Boards using SPI protocol same as previous lab experiment using UART?

#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
#define GPIOA_MODER (*((int *)0x40020000))
#define GPIOA_AFRL (*((int *)0x40020020))
#define GPIOA_ODR (*((int *)0x40020014))
#define NVIC_ISER1 (*((int *)0xE000E104))

//UART1 Addresses	
#define SPI1_CR1 (*((int *)0x40013000))
#define SPI1_CR2 (*((int *)0x40013004))
#define SPI1_SR (*((int *)0x40013008))
#define SPI1_DR (*((int *)0x4001300C))
	
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
	
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_PUPDR (*((int *)0x4002080C))

char ch;

void SPI1_MUX_init()
{
	RCC_AHB1ENR |= 0x7;//set bit 0,1,2 to enable clock for port A,B&C 
	while(!((RCC_AHB1ENR&0x1)&&(RCC_AHB1ENR&0x2)&&(RCC_AHB1ENR&0x4)))//wait until clock is set
	{
		;
	}
	GPIOA_MODER &= 0xFFFF00FF;//clear 15-8 bits
	GPIOA_MODER |= 0x0000AA00;//load '10101010' into 15-8 bit fiels ,PA7-PA4 as Alternative function mode 
	GPIOA_AFRL	&= 0x0000FFFF;//clear AFRL7-AFRL4
	GPIOA_AFRL	|= 0x55550000;//load '0111' into AFRL7-AFRL4 to set as SPI1
	
	GPIOB_MODER &= 0xCFFFFFFF;//clear 27th & 26th bits
	GPIOB_MODER |= 0x10000000;//load "01" into 27th-26th bit fields
	GPIOC_MODER &= 0xFFCFFFFF;//clear 21th & 20th bits
	GPIOC_MODER |= 0x00000000;//load "01" into 21tH-20th bit fields
	GPIOC_PUPDR &= 0xFFCFFFFF;//clear 21th & 20th bits
	GPIOC_PUPDR |= 0x00100000;//load "01" into 21th-20th bit fields
}

void KM_SPI1_init_cofig()
{
	RCC_APB2ENR |= 0x1<<12;//Enable clock for SPI1
	while(!(RCC_APB2ENR&(0x1<<12)));//wail until clock is set
	SPI1_CR2 |= 0x1<<6;
	SPI1_CR1 |= 0x1 << 2;//Master select
	SPI1_CR1 |= 0x1<<9;//Enable SSM
	SPI1_CR1 |= 0x1<<8;//Enable SSI
	SPI1_CR1 |= 0x1<<6;//Enable SPI1_EN
}
void KM_SPI1_outchar(unsigned char data)
{
	while(!(SPI1_SR&0x1<<1))//wait until Transmitter empty
	{
		;
	}
	SPI1_DR = data;//load data into data register
}
void Delay(int x)
{
	while(x--)
	{
		;
	}
}
int main()
{
	SPI1_MUX_init();
	KM_SPI1_init_cofig();
	GPIOB_ODR |= (0x1<<14);
	NVIC_ISER1 |= 0x1<<3;
	while(1)
	{
		if(!(GPIOC_IDR&(0X1<<10))){
			KM_SPI1_outchar('R');//Transer 'A' char to outside device
		}
		if(ch=='G')
		{
			GPIOB_ODR ^= (0x1<<14);
			ch=0;
		}
		Delay(100000);
	}
}

void SPI1_IRQHandler(void)
{
	 ch=(SPI1_DR&0xFF);
}

