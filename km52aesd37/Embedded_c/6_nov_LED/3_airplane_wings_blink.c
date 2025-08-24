/*Lab Experiment 2:
Airplane wing Lights blinking Delays:
USER LED1 (GREEN): ON (50msec), OFF (50msec), ON (50msec), OFF (150msec) periodically. USER LED2 (RED): ON (50msec), OFF (250msec), ON (50msec), OFF (500msec) periodically.		*/

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
	GPIOB_MODER &= 0xC3FFFFFF;//clear 27th-26th bits & 29th-28th bits
	GPIOB_MODER |= 0x14000000;//load "01" into 27th-26th & 29th-28th bit fields
}
void Delay(int x)
{
	int i;
	for(i=x;i>0;i--)
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
		GPIOB_ODR &= ~(0x1<<14);
		Delay(125000);
		GPIOB_ODR |= (0x1<<14);
		Delay(125000);
		GPIOB_ODR &= ~(0x1<<13);
		Delay(125000);
		GPIOB_ODR |= (0x1<<13);
		Delay(625000);
		GPIOB_ODR &= ~(0x1<<14);
		Delay(125000);
		GPIOB_ODR |= (0x1<<14);
		Delay(375000);
		GPIOB_ODR &= ~(0x1<<13);
		Delay(125000);
		GPIOB_ODR |= (0x1<<13);
		Delay(1250000);
	}
	return 0;
}

