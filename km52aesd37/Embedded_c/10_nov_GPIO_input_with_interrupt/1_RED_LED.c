/*Lab Experiment 8: Write a program Request an interrupt on the Falling edge of ENTER Switch, whenever the user 
button is pressed and increment a counter in the interrupt and RED LED is ON.	*/

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

int count=0;

void RED_SW_init()
{
	RCC_AHB1ENR |= 0X6 ;//Enable port B&C clock
	while(!((RCC_AHB1ENR&0x2)&&(RCC_AHB1ENR&0X4)))//wait for until port B&C clock enable
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
	GPIOC_MODER |= 0x00000000;//load "01" into 21tH-20th bit fields
	GPIOC_PUPDR &= 0xFFCFFFFF;//clear 21th & 20th bits
	GPIOC_PUPDR |= 0x00100000;//load "01" into 21th-20th bit fields
}	
void Ent_SW_init()
{
	RCC_APB2ENR |= (0x1<<14);
	while(!(RCC_APB2ENR&0x1<<14))
	{
		;
	}
	//Interrupt PC10 is connected to EXTI
	SYSCFG_EXTICR3 &= 0xFFFFF0FF;
	SYSCFG_EXTICR3 |= 0x00000200;
	//10th bit of FTSR is set
	EXTI_FTSR |= 0x00000400;
	EXTI_IMR |= 0x00000400;
	//EXTI_PR &= ~(0x1<<10);
	NVIC_ISER1 |= 0X1<<8;
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
	RED_config();
	Enter_SW_config();
	//RESET Button press to turn OFF LED
	GPIOB_ODR |= (0x1<<13);
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
		EXTI_PR |= 0x1<<10;
	}

}

