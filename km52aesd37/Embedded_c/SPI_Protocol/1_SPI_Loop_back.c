/*Experiment 1:Write a pseudo code and Embedded C program to SPI1 Configuration using the below conditions,
	And transmit character ‘A’ and Receive same character using hardware Loop back.		*/
#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
#define GPIOA_MODER (*((int *)0x40020000))
#define GPIOA_AFRL (*((int *)0x40020020))
#define GPIOA_ODR (*((int *)0x40020014))

//UART1 Addresses	
#define SPI1_CR1 (*((int *)0x40013000))
#define SPI1_CR2 (*((int *)0x40013004))
#define SPI1_SR (*((int *)0x40013008))
#define SPI1_DR (*((int *)0x4001300C))

char ch;

void SPI1_MUX_init()
{
	RCC_AHB1ENR |= 0x1;//set bit 0 to enable clock for port A 
	while(!(RCC_AHB1ENR&0x1))//wait until clock is set
	{
		;
	}
	GPIOA_MODER &= 0xFFFF00FF;//clear 15-8 bits
	GPIOA_MODER |= 0x0000AA00;//load '10101010' into 15-8 bit fiels ,PA7-PA4 as Alternative function mode 
	GPIOA_AFRL	&= 0x0000FFFF;//clear AFRL7-AFRL4
	GPIOA_AFRL	|= 0x55550000;//load '0111' into AFRL7-AFRL4 to set as SPI1
}

void KM_SPI1_init_cofig()
{
	RCC_APB2ENR |= 0x1<<12;//Enable clock for SPI1
	while(!(RCC_APB2ENR&(0x1<<12)));//wail until clock is set
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

unsigned char KM_SPI1_inchar(void)
{
	while(!(SPI1_SR&0x1))//wait until Receiver full
	{
		;
	}
	return (SPI1_DR&0xFF);//return data
}

int main()
{
	SPI1_MUX_init();
	KM_SPI1_init_cofig();
	while(1)
	{
		KM_SPI1_outchar('A');//Transer 'A' char to outside device
		ch = KM_SPI1_inchar();//Receiving data from outside data
		ch++;
	}
}


