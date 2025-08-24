/*Lab Experiment 4: Use “SW_ENT” and declare “counter” global variable. Your program should increment counter by one, every time switch is pressed. Note how the value of counter changes on each “ENTER SWITCH” press. Use debugger and add Counter to “Watch Expression” window. Does the value of counter increment by one always?
Note: Define counter as a global variable and in debug perspective use continuous refresh option (You will find Continuous Refresh button on top of the Expression Window). You can use step debugging or breakpoints to check the variable value.
Hint: To add variable to Expression Window, select and right click the variable name and select “Add Watch Expression”. To view Expression Window, click on View button from Keil menu bar and select Expressions.*/

#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
	
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_PUPDR (*((int *)0x4002080C))
int count=0;

void RED_init()
{
	RCC_AHB1ENR |= 0X6;//Enable port B& port C clock
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
			count++;
			GPIOB_ODR ^= (0x1<<13);
			Delay();
		}
	}
	return 0;
}

