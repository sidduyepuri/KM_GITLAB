#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_PUPDR (*((int *)0x4002080C))
	
#define RCC_APB2ENR (*((int *)0x40023844))
#define SYSCFG_EXTICR3 (*((int *)0x40013810))
#define EXTI_FTSR (*((int *)0x40013C0C))
#define EXTI_IMR (*((int *)0x40013C00))

#define NVIC_ISER1 (*((int *)0xE000E104))
	
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
	NVIC_ISER1 |= 0X1<<8;
}
