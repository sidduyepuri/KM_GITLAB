/*Lab Experiment 3: Whenever SW_UP is pressed RED LED is ON, whenever SW_DN is pressed GREEN LED is ON. Assign breakpoints after if condition and click run button in debugger window. Whenever SW1/SW2 presses program stops at any one of the breakpoint.*/

#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
	
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_PUPDR (*((int *)0x4002080C))
int count=0;

void RED_GREEN_init()
{
	RCC_AHB1ENR |= 0X6;//Enable port B clock
	while(!((RCC_AHB1ENR&0x2)&&(RCC_AHB1ENR&0X4)))//wait for until port B clock enable
	{
		;
	}
}
void RED_GREEN_config(void)
{
	GPIOB_MODER &= 0xC3FFFFFF;//clear 27th & 26th bits
	GPIOB_MODER |= 0x14000000;//load "01" into 27th-26th bit fields
}
void Enter_SW_config(void)
{
	GPIOC_MODER &= 0xFFF0FFFF;//clear 16,17,18,19 bits
	GPIOC_MODER |= 0x00000000;//load "00" into 16,17,18,19 bit fields
	GPIOC_PUPDR &= 0xFFF5FFFF;//clear 16,17,18,19 bits
	GPIOC_PUPDR |= 0x00050000;//load "01" into 16,17,18,19 bit fields
}
void Delay()
{
	int i;
	for(i=0;i<500000;i++)
	{
		;
	}
}
int main()
{
	//initialization phase
	RED_GREEN_init();
	//cofiguration phase
	RED_GREEN_config();
	Enter_SW_config();
	//RESET Button press to turn OFF LED's
	GPIOB_ODR |= (0x1<<13);
	GPIOB_ODR |= (0x1<<14);
	//operation phase
	while(1)
	{
		if(!(GPIOC_IDR&0X1<<8))
		{	
			GPIOB_ODR &= ~(0x1<<13);
		}
		if(!(GPIOC_IDR&0X1<<9))
		{	
			GPIOB_ODR &= ~(0x1<<14);
		}
	}
	return 0;
}

