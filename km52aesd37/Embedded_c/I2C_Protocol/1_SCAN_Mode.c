//Experiment 1: Write a Pseudo code, draw flow charts and write Embedded C Program to scan I2C devices and show the list of found devices? Use the Polling method. Set I2C clock frequency 100KHZ & Master mode

#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB1ENR (*((int *)0x40023840))
	
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
#define GPIOB_AFRL (*((int *)0x40020420))
#define GPIOB_PUPDR (*((int *)0x4002040C))
#define GPIOB_OTYPER (*((int *)0x40020404))

//I2C1 Addresses	
#define I2C1_CR1 (*((int *)0x40005400))
#define I2C1_CR2 (*((int *)0x40005404))
#define I2C1_DR (*((int *)0x40005410))
#define I2C1_OAR1 (*((int *)0x40005408))
#define I2C1_OAR2 (*((int *)0x4000540C))
#define I2C1_SR1 (*((int *)0x40005414))
#define I2C1_SR2 (*((int *)0x40005418))
#define I2C1_CCR (*((int *)0x4000541C))
int Device;
#include "SysTickTimer.h"
#include "LCD_code.h"


void I2C1_MUX_init()
{
	RCC_AHB1ENR |= 0x1<<1;
	while(!(RCC_AHB1ENR&0x1<<1));
	GPIOB_MODER &= 0xFFFF0FFF;
	GPIOB_MODER |= 0x0000A000;
	GPIOB_AFRL &= 0x00FFFFFF;
	GPIOB_AFRL |= 0x44000000;
	GPIOB_OTYPER &= 0xFFFFFF3F;
	GPIOB_OTYPER |= 0x000000C0;
}

void I2C1_config()
{
	RCC_APB1ENR |= 0x1<<21;
	I2C1_CCR |= 0x0050;
	I2C1_CR2 &= ~(0x3F);
	I2C1_CR2 |= 0x10;
	I2C1_CR1 |= 0x1;
}

int KM_I2C_IsDeviceReady(int DevAddress,unsigned int Timeout)
{
	int Dummy_read=0;
	I2C1_CR1 |= 0x1;//Enable PE(peripheral enable)
	I2C1_CR1 |= 0x1<<10;//set 10th bit to enable ACK (Acknowledge)
	while(I2C1_SR2 &0x2);//wait until BUSY bit in sr2 becomes zero
	I2C1_CR1 |= 0x1<<8;//set 8th bit in CR1 reg to Enable START bit
	while(!(I2C1_SR1&0x1));//wait until SB bit is set
	Dummy_read = I2C1_SR1;
	
	I2C1_DR = DevAddress;
	while((!(I2C1_SR1 & (0x1<<1)) && (!(I2C1_SR1 & (0x1<<10)))) && Timeout)
	{
		Timeout--;
		KM_mdelay(1);
		if(Timeout<0)
		{
			return 0;
		}
	}
	if(I2C1_SR1&0x1<<1)
	{
		I2C1_SR1 &= ~(0x1<<10);
		I2C1_CR1 |= 0x1<<9;//set 8th bit in CR1 reg to Enable START bit
		I2C1_CR1 &= ~(0x1);//Disable PE(peripheral enable)
		return 1;
	}
	else
	{
		I2C1_SR1 &= ~(0x1<<10);
		I2C1_CR1 |= 0x1<<9;//set 8th bit in CR1 reg to Enable START bit
		I2C1_CR1 &= ~(0x1);//Disable PE(peripheral enable)
		return 0;
	}
	
}

int main()
{
	int i;
	I2C1_MUX_init();
	RCC_init();
	LCD_config();
	STK_Timer_init();
	KM_LCD_init();
	I2C1_config();
	
	for(i=0;i<128;i++)
	{
		if(KM_I2C_IsDeviceReady((i<<1),200)==1)
		{
			Device = i;
			if(i==80)
				KM_LCD_String("EEPROM FOUND-80");
			if(i==104)
			{
				KM_LCD_write_cmd(0x01);
				KM_LCD_String("RTC FOUND-104");
			}
			KM_mdelay(5000);
		}
	}
}

