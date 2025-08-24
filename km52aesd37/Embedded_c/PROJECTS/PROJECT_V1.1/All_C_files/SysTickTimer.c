//SysTick timer Addresses
#define STK_CTRL (*((int *)0xE000E010))
#define STK_LOAD (*((int *)0xE000E014))
#define STK_VAL (*((int *)0xE000E018))
	
//System tick timer initialization
void 	STK_Timer_init()
{
	STK_CTRL |= 0X5;//write '101' bit fiels 0,1,2 to enable,
	STK_VAL = 0X578;//write G.V to STK_VAL
}

void KM_mdelay(int m)
{
	STK_LOAD = m*16000;
	while(!(STK_CTRL&0x1<<16))//wait until COUNTFLAG is set
	{
		;
	}
}
void KM_udelay(int m)
{
	STK_LOAD = m*1600;
	while(!(STK_CTRL&0x1<<16))//wait until COUNTFLAG is set
	{
		;
	}
}

