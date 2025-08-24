/*Lab Experiment 9: Write an Embedded C Program Whenever SW_UP press RED LED is ON, whenever SW_DN press 
GREEN LED is ON using Falling edge GPIO interrupt.		*/

#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
	
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_PUPDR (*((int *)0x4002080C))
	
#define RCC_APB2ENR (*((int *)0x40023844))
#define SYSCFG_EXTICR3 (*((int *)0x40013810))
#define EXTI_FTSR (*((int *)0x40013C0C))
#define EXTI_IMR (*((int *)0x40013C00))
#define EXTI_PR (*((int *)0x40013C14))
#define NVIC_ISER1 (*((int *)0xE000E104))
#define NVIC_ISER0 (*((int *)0xE000E100))

int count=0;

void RED_SW_init()
{
	RCC_AHB1ENR |= 0X6 ;//Enable port B clock
	while(!((RCC_AHB1ENR&0x2)&&(RCC_AHB1ENR&0X4)))//wait for until port B clock enable
	{
		;
	}
}

void RED_GREEN_BUZ_config(void)
{
	GPIOB_MODER &= 0xC0FFFFFF;//clear 27th & 26th bits
	GPIOB_MODER |= 0x15000000;//load "01" into 27th-26th bit fields
}
void Enter_SW_config(void)
{
	GPIOC_MODER &= 0xFFC0FFFF;//clear 21th & 20th bits
	GPIOC_MODER |= 0x00000000;//load "01" into 21tH-20th bit fields
	GPIOC_PUPDR &= 0xFFC0FFFF;//clear 21th & 20th bits
	GPIOC_PUPDR |= 0x00150000;//load "01" into 21th-20th bit fields
}	
void Ent_SW_init()
{
	RCC_APB2ENR |= (0x1<<14);
	while(!(RCC_APB2ENR&0x1<<14))
	{
		;
	}
	//Interrupt PC10 is connected to EXTI
	SYSCFG_EXTICR3 &= 0xFFFFF000;
	SYSCFG_EXTICR3 |= 0x00000222;
	//10th bit of FTSR is set
	EXTI_FTSR |= 0x00000700;
	EXTI_IMR |= 0x00000700;
	//EXTI_PR &= ~(0x1<<10);
	NVIC_ISER1 |= 0X1<<8;
	NVIC_ISER0 |= 0X1<<23;
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
	RED_SW_init();
	//cofiguration phase
	Ent_SW_init();
	RED_GREEN_BUZ_config();
	Enter_SW_config();
	//RESET Button press to turn OFF LED
	GPIOB_ODR |= (0x1<<13);
	GPIOB_ODR |= (0x1<<14);
	//operation phase
	while(1)
	{
		;
	}
	return 0;
}

void EXTI15_10_IRQHandler(void)
{
	
	if(EXTI_PR&0x1<<10)
	{
		count++;
		GPIOB_ODR ^= (0x1<<13);
	}
	EXTI_PR |= 0x1<<10;
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI_PR&0x1<<8)
	{
		GPIOB_ODR ^= (0X1<<14);
		EXTI_PR |= 0x1<<8;
	}
	if(EXTI_PR&0x1<<9)
	{
		GPIOB_ODR ^= (0X1<<12);
		EXTI_PR |= 0x1<<9;
	}
}

