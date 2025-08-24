#include "lcd.h"
#include "SysTickTimer.h"
#define RCC_AHB1ENR (*((int *)0x40023830))
#define GPIOB_MODER (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))
	
#define GPIOC_MODER (*((int *)0x40020800))
#define GPIOC_IDR (*((int *)0x40020810))
#define GPIOC_PUPDR (*((int *)0x4002080C))
char str2[20];
volatile int temp;
int k;

void SW_init_config()
{
	GPIOB_MODER &= 0xF3FFFFFF;//clear 27th & 26th bits
	GPIOB_MODER |= 0x04000000;//load "01" into 27th-26th bit fields
	
	GPIOC_MODER &= 0xFFC0FFFF;//clear 21th & 20th bits
	GPIOC_MODER |= 0x00000000;//load "01" into 21tH-20th bit fields
	GPIOC_PUPDR &= 0xFFC5FFFF;//clear 21th & 20th bits
	GPIOC_PUPDR |= 0x00150000;//load "01" into 21th-20th bit fields
}

void Task5_SWMS_Config(unsigned char T_date[])
{
	GPIOB_ODR |= (0x1<<13);//set 13th bit to turn OFF Red led
	if(!(GPIOC_IDR&0x1<<10))//check SW_ENT is pressed
	{
		KM_LCD_write_cmd(0x01);//clear LCD
		KM_LCD_write_cmd(0x80);//cursor moves to first line
		KM_LCD_String("ENTER DATE&TIME");
		KM_LCD_write_cmd(0xC0);//cursor moves to second line
		KM_LCD_String("Y:DN   N:UP");
		KM_mdelay(1000);
		KM_mdelay(1000);
		while(1)
		{
			if(!(GPIOC_IDR&0x1<<9))
			{
				for(k=0;k<10;k++)
				{
					T_date[k]=0;
				}
				KM_LCD_write_cmd(0x01);
				KM_LCD_write_cmd(0x84);
				KM_LCD_String("SS:MM:HH");
				KM_LCD_write_cmd(0xC4);
				KM_LCD_String("00:00:00");
				KM_mdelay(1000);
				while(T_date[0]>=0&&(GPIOC_IDR&0x1<<10))
				{
					if(((GPIOC_IDR&0x1<<8)==0)&&(temp==0)){
						T_date[0]++;
						temp=1;
					}
					if(((GPIOC_IDR&0x1<<9)==0)&&(temp==0)){
						T_date[0]--;
						temp=1;
					}
					str2[0]=(T_date[0]/10)+48;
					str2[1]=(T_date[0]%10)+48;
					KM_LCD_write_cmd(0xC4);
					KM_LCD_String(str2);
					if(T_date[0]<0||T_date[0]>60)
					{
						GPIOB_ODR &= ~(0x1<<13);
						T_date[0]=0X00;
					}
					else
						GPIOB_ODR |= (0x1<<13);
					if((GPIOC_IDR&0x1<<8)&&(GPIOC_IDR&0x1<<9)){
						temp=0;
					}
					KM_mdelay(100);
				}	
				T_date[0]=((T_date[0]/10)*16)+((T_date[0]%10)*1);
				KM_mdelay(1000);
				KM_mdelay(1000);
				while(T_date[1]>=0&&(GPIOC_IDR&0x1<<10))
				{
					if(((GPIOC_IDR&0x1<<8)==0)&&(temp==0)){
						T_date[1]++;
						temp=1;
					}
					if(((GPIOC_IDR&0x1<<9)==0)&&(temp==0)){
						T_date[1]--;
						temp=1;
					}
					str2[0]=(T_date[1]/10)+48;
					str2[1]=(T_date[1]%10)+48;
					KM_LCD_write_cmd(0xC7);
					KM_LCD_String(str2);
					if(T_date[1]<0&&T_date[0]>60)
					{
						GPIOB_ODR &= ~(0x1<<13);
						T_date[1]=0x00;
					}
					else
						GPIOB_ODR |= (0x1<<13);
					if((GPIOC_IDR&0x1<<8)&&(GPIOC_IDR&0x1<<9)){
						temp=0;
					}
				}
				T_date[1]=((T_date[1]/10)*16)+((T_date[1]%10)*1);
				KM_mdelay(1000);
				KM_mdelay(1000);
				while(T_date[2]>=0&&(GPIOC_IDR&0x1<<10))
				{
					if(((GPIOC_IDR&0x1<<8)==0)&&(temp==0)){
						T_date[2]++;
						temp=1;
					}
					if(((GPIOC_IDR&0x1<<9)==0)&&(temp==0)){
						T_date[2]--;
						temp=1;
					}
					str2[0]=(T_date[2]/10)+48;
					str2[1]=(T_date[2]%10)+48;
					KM_LCD_write_cmd(0xCA);
					KM_LCD_String(str2);
					if(T_date[2]<0||T_date[2]>24)
					{
						GPIOB_ODR &= ~(0x1<<13);
						T_date[2]=0x00;
					}
					else
						GPIOB_ODR |= (0x1<<13);
					if((GPIOC_IDR&0x1<<8)&&(GPIOC_IDR&0x1<<9)){
						temp=0;
					}
				}
				T_date[2]=((T_date[2]/10)*16)+((T_date[2]%10)*1);
				KM_mdelay(1000);
				KM_LCD_write_cmd(0x01);
				KM_LCD_write_cmd(0x82);
				KM_LCD_String("WW:DD:MM:YY");
				KM_LCD_write_cmd(0xC2);
				KM_LCD_String("00:00:00:00");
				KM_mdelay(1000);
				while(T_date[3]>=0&&(GPIOC_IDR&0x1<<10))
				{
					if(((GPIOC_IDR&0x1<<8)==0)&&(temp==0)){
						T_date[3]++;
						temp=1;
					}
					if(((GPIOC_IDR&0x1<<9)==0)&&(temp==0)){
						T_date[3]--;
						temp=1;
					}
					str2[0]=(T_date[3]/10)+48;
					str2[1]=(T_date[3]%10)+48;
					KM_LCD_write_cmd(0xC2);
					KM_LCD_String(str2);
					if(T_date[3]<0||T_date[3]>7)
					{
						GPIOB_ODR &= ~(0x1<<13);
						T_date[3]=0x00;
					}
					else
						GPIOB_ODR |= (0x1<<13);
					if((GPIOC_IDR&0x1<<8)&&(GPIOC_IDR&0x1<<9)){
						temp=0;
					}
				}
				T_date[3]=((T_date[3]/10)*16)+((T_date[3]%10)*1);
				KM_mdelay(1000);
				KM_mdelay(1000);
				while(T_date[4]>=0&&(GPIOC_IDR&0x1<<10))
				{
					if(((GPIOC_IDR&0x1<<8)==0)&&(temp==0)){
						T_date[4]++;
						temp=1;
					}
					if(((GPIOC_IDR&0x1<<9)==0)&&(temp==0)){
						T_date[4]--;
						temp=1;
					}
					str2[0]=(T_date[4]/10)+48;
					str2[1]=(T_date[4]%10)+48;
					KM_LCD_write_cmd(0xC5);
					KM_LCD_String(str2);
					if(T_date[4]<0||T_date[4]>31)
					{
						GPIOB_ODR &= ~(0x1<<13);
						T_date[4]=0x00;
					}
					else
						GPIOB_ODR |= (0x1<<13);
					if((GPIOC_IDR&0x1<<8)&&(GPIOC_IDR&0x1<<9)){
						temp=0;
					}
				}
				T_date[4]=((T_date[4]/10)*16)+((T_date[4]%10)*1);
				KM_mdelay(1000);
				KM_mdelay(1000);
				while(T_date[5]>=0&&(GPIOC_IDR&0x1<<10))
				{
					if(((GPIOC_IDR&0x1<<8)==0)&&(temp==0)){
						T_date[5]++;
						temp=1;
					}
					if(((GPIOC_IDR&0x1<<9)==0)&&(temp==0)){
						T_date[5]--;
						temp=1;
					}
					str2[0]=(T_date[5]/10)+48;
					str2[1]=(T_date[5]%10)+48;
					KM_LCD_write_cmd(0xC8);
					KM_LCD_String(str2);
					if(T_date[5]<0||T_date[5]>12)
					{
						GPIOB_ODR &= ~(0x1<<13);
						T_date[5]=0x00;
					}
					else
						GPIOB_ODR |= (0x1<<13);
					if((GPIOC_IDR&0x1<<8)&&(GPIOC_IDR&0x1<<9))
					{
						temp=0;
					}
				}
				T_date[5]=((T_date[5]/10)*16)+((T_date[5]%10)*1);
				KM_mdelay(1000);
				KM_mdelay(1000);
				while(T_date[6]>=0&&(GPIOC_IDR&0x1<<10))
				{
					if(((GPIOC_IDR&0x1<<8)==0)&&(temp==0)){
						T_date[6]++;
						temp=1;
					}
					if(((GPIOC_IDR&0x1<<9)==0)&&(temp==0)){
						T_date[6]--;
						temp=1;
					}
					str2[0]=(T_date[6]/10)+48;
					str2[1]=(T_date[6]%10)+48;
					KM_LCD_write_cmd(0xCB);
					KM_LCD_String(str2);
					if(T_date[6]<0||T_date[6]>99)
					{
						GPIOB_ODR &= ~(0x1<<13);
						T_date[6]=0x00;
					}
					else
						GPIOB_ODR |= (0x1<<13);
					if((GPIOC_IDR&0x1<<8)&&(GPIOC_IDR&0x1<<9)){
						temp=0;
					}
				}
				T_date[6]=((T_date[6]/10)*16)+((T_date[6]%10)*1);
				KM_mdelay(1000);
				break;
			}
			else if(!(GPIOC_IDR&0x1<<8))
			{
				break;
			}
		}
	}
}
