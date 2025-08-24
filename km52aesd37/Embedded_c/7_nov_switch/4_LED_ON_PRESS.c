/*Read SW_ENT, if switch is press RED LED is ON otherwise RED LED is OFF. Note that RED LED
should remain ON for the duration switch is kept pressed i.e. RED LED should turn OFF when switch is released.		*/

#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
	
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_PUPDR (*((int *)0x4002080C))
void RED_init()
{
	RCC_AHB1ENR |= 0X6;//Enable port B & port C clock
	while(!((RCC_AHB1ENR&0x2)&&(RCC_AHB1ENR&0X4)))//wait for until port B & port C clock enable
	{
		;
	}
}
void RED_config(void)
{
	GPIOB_MODER &= 0xF3FFFFFF;//clear 27th & 26th bits
	GPIOB_MODER |= 0x04000000;//load "01" into 27th-26th bit fields
}
void Enter_SW_config(void)
{
	GPIOC_MODER &= 0xFFCFFFFF;//clear 21th & 20th bits
	GPIOC_MODER |= 0x00000000;//load "00" into 21tH-20th bit fields
	GPIOC_PUPDR &= 0xFFCFFFFF;//clear 21th & 20th bits
	GPIOC_PUPDR |= 0x00100000;//load "01" into 21th-20th bit fields
}
int main()
{
	//initialization phase
	RED_init();
	//cofiguration phase
	RED_config();
	Enter_SW_config();
	//RESET Button press to turn OFF LED
	GPIOB_ODR |= (0x1<<13);
	//operation phase
	while(1)
	{
		if(!(GPIOC_IDR&0X1<<10))
		{	
			GPIOB_ODR ^= (0x1<<13);
		}
	}
	return 0;
}

