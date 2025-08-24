//Lab Experiment 7: Whenever SW_ENT Press turn ON BUZZER up to 250msec and Turn OFF BUZZER.

#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
	
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_PUPDR (*((int *)0x4002080C))

void RCC_init()
{
	RCC_AHB1ENR |= 0X6;//Enable port B & port C clock
	while(!((RCC_AHB1ENR&0x2)&&(RCC_AHB1ENR&0X4)))//wait for until port B&C clock enable
	{
		;
	}
}
void BUZZER_config(void)
{
	GPIOB_MODER &= 0xFCFFFFFF;
	GPIOB_MODER |= 0x01000000;
}
void Enter_SW_config(void)
{
	GPIOC_MODER &= 0xFFCFFFFF;
	GPIOC_MODER |= 0x00000000;
}
void Delay()
{
	int i;
	for(i=0;i<415000;i++)
	{
		;
	}
}
int main()
{
	//initialization phase
	RCC_init();
	//cofiguration phase
	BUZZER_config();
	Enter_SW_config();
	//RESET Button press to turn OFF LED
	//operation phase
	while(1)
	{
		if(!(GPIOC_IDR&0X1<<10))
		{	
			GPIOB_ODR ^= (0x1<<12);
			Delay();
		}
	}
	return 0;
}

