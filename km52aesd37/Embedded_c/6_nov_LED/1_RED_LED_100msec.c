#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
void RED_init()
{
	RCC_AHB1ENR |= 0X1<<1;//Enable port B clock
	while(!(RCC_AHB1ENR&0x2))//wait for until port B clock enable
	{
		;
	}
}
void RED_config(void)
{
	GPIOB_MODER &= 0xF3FFFFFF;//clear 27th & 26th bits
	GPIOB_MODER |= 0x04000000;//load "01" into 27th-26th bit fields
}
void Delay()
{
	int i;
	for(i=0;i<167200;i++)
	{
		;
	}
}
int main()
{
	RED_init();
	RED_config();
	while(1)
	{
		GPIOB_ODR &= ~(0x1<<13);
		Delay();
		GPIOB_ODR |= (0x1<<13);
		Delay();
	}
	return 0;
}
