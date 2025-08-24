/*1) Toggle PB13 (RED LED) every 100 msec delay using SysTick timer using 16 MHZ system clock source.
     And also test minimum and maximum delays of 16MHZ timer.
Draw flowcharts and write an embedded C program for the below 2 methods
	a: polling method		*/
#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))

//SysTick timer Addresses
#define STK_CTRL (*((int *)0xE000E010))
#define STK_LOAD (*((int *)0xE000E014))
#define STK_VAL (*((int *)0xE000E018))

void RED_init()
{
	RCC_AHB1ENR |= 0X1<<1;//Enable port B clock
	while(!(RCC_AHB1ENR&0x2))//wait for until port B clock enable
	{
		;
	}
}
//System tick timer initialization
void 	STK_Timer_init()
{
	STK_CTRL |= 0X5;
	STK_VAL = 0X578;
}

void RED_config(void)
{
	GPIOB_MODER &= 0xF3FFFFFF;//clear 27th & 26th bits
	GPIOB_MODER |= 0x04000000;//load "01" into 27th-26th bit fields
}

int main()
{
	//phase 1: Initialization phase
	RED_init();
	STK_Timer_init();
	//Phase 2: Configuration phase
	RED_config();
	STK_LOAD = 1600000;
	//Phase 3: operation phase
	while(1)
	{
		GPIOB_ODR &= ~(0x1<<13);
		while(!(STK_CTRL&0x1<<16))
		{
			;
		}
		GPIOB_ODR |= (0x1<<13);
		while(!(STK_CTRL&0x1<<16))
		{
			;
		}
	}
	return 0;
}

