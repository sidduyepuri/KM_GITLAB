/*2) Write a program to implement generic delay functions using Sys Tick timer with polling method.
	void KM_mdelay(int );  
	void KM_udelay(int ); 			*/ 

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
	STK_CTRL |= 0X5;//write '101' bit fiels 0,1,2 to enable,
	STK_VAL = 0X578;//write G.V to STK_VAL
}

void KM_mdelay(int m)
{
	STK_LOAD = m*16000;
	while(!(STK_CTRL&0x1<<16))
	{
		;
	}
}

void KM_udelay(int m)
{
	STK_LOAD = m*16;
	while(!(STK_CTRL&0x1<<16))
	{
		;
	}
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
	//Phase 3: operation phase
	while(1)
	{
		KM_mdelay(100);
		GPIOB_ODR &= ~(0x1<<13);
		KM_udelay(100000);
		GPIOB_ODR |= (0x1<<13);

	}
	return 0;
}


