#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
void KM_mdelay(int );

void RCC_init()
{
	RCC_AHB1ENR |= 0X2;//Enable port B clock
	while(!(RCC_AHB1ENR&0x2))//wait for until port B clock enable
	{
		;
	}
}

void LCD_config(void)
{
	GPIOB_MODER &= 0xFFFCF000;//clear 11-0 & 16-15 bits
	GPIOB_MODER |= 0x00010555;//load "01" into 11-0 & 16-15 bit fields
}

void write_high_nibble(unsigned char data)
{
	GPIOB_ODR &= 0xFFF0;//clear PB3-PB0 bit fields 
	GPIOB_ODR |= data>>4;//higher nibble of data
	GPIOB_ODR |= 0x1<<8;//Enable LCD to accept higher nibble data
	KM_mdelay(10);//delay wait for accept data
	GPIOB_ODR &= ~(0x1<<8);//Disable LCD
}

void write_lower_nibble(unsigned char data)
{
	GPIOB_ODR &= 0xFFF0;//clear PB3-PB0 bit fields 
	GPIOB_ODR |= (data&0x0F);//lower nibble of data
	GPIOB_ODR |= 0x1<<8;//Enable LCD to accept higher nibble data
	KM_mdelay(10);//delay wait for accept data
	GPIOB_ODR &= ~(0x1<<8);//Disable LCD
}	

void KM_LCD_write_cmd(unsigned char data)
{
	GPIOB_ODR &= ~(0x1<<4);//clear PB4 (RS=0) as commmand register
	write_high_nibble(data);
	write_lower_nibble(data);
}

void KM_LCD_write_data(unsigned char data)
{
	GPIOB_ODR |= (0x1<<4);//clear PB4 (RS=1) as data register
	write_high_nibble(data);
	write_lower_nibble(data);
}

void KM_LCD_init()
{
	KM_mdelay(20);
	KM_LCD_write_cmd(0x33);//say 4 wire data communication
	KM_mdelay(1);
	KM_LCD_write_cmd(0x32);
	KM_LCD_write_cmd(0x0C);//Display ON, Cursor OFF
	KM_LCD_write_cmd(0x01);//clear LCD
}

void KM_LCD_String(char str[])
{
	int i=0;
	for(;str[i];i++)
	{
		KM_LCD_write_data(str[i]);//character by chararcter sending data
	}
}

