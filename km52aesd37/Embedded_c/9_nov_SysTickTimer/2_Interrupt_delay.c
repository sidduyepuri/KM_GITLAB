/*1) Toggle PB13 (RED LED) every 100 msec delay using SysTick timer using 16 MHZ system clock source.
     And also test minimum and maximum delays of 16MHZ timer.
Draw flowcharts and write an embedded C program for the below 2 methods
	b:Interrupt method		*/

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

void 	STK_Timer_init()
{
	STK_CTRL |= 0X7;
	STK_VAL = 0X578;
	STK_LOAD = 1600000;

}

void SysTick_Handler(void)
{
	GPIOB_ODR ^= (0x1<<13);
}

void RED_config(void)
{
	GPIOB_MODER &= 0xF3FFFFFF;//clear 27th & 26th bits
	GPIOB_MODER |= 0x04000000;//load "01" into 27th-26th bit fields
}

int main()
{
	RED_init();
	STK_Timer_init();
	RED_config();
	while(1)
	{
		;
	}
	return 0;
}

