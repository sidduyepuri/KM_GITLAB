//RCC
#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR  (*((int *)0x40023844))

//GPIOA
#define GPIOA_MODER  (*((int *)0x40020000)) 
#define GPIOA_AFRH (*((int *)0x40020024))

//UART1 Addresses
#define UART1_SR (*((int *)0x40011000))
#define UART1_DR (*((int *)0x40011004))
#define UART1_CR1 (*((int *)0x4001100C))
#define UART1_BRR (*((int *)0x40011008))

#include<stdio.h> 
#include<stdarg.h>

void UART1_MUX_init()
{
	RCC_AHB1ENR |= 0x1;//set bit 0 to enable clock for port A
	while(!(RCC_AHB1ENR&0x1))//wait until clock is set
	{
		;
	}
	GPIOA_MODER &= 0xFFC3FFFF;//clear 21-18 bits
	GPIOA_MODER |= 0x00280000;//load '1010' into 21-18 bit fiels ,PA9 & PA10 as Alternative function mode 
	GPIOA_AFRH &= 0xFFFFF00F;//clear AFRH9,AFRH10
	GPIOA_AFRH |= 0x00000770;//load '0111' into both AFRH9,AFRH10 to set as UART1
}

void KM_UART_init_cofig()
{
	RCC_APB2ENR |= 0x1<<4;//Enable clock for UART1
	while(!(RCC_APB2ENR&0x10));//wail until clock is set
	UART1_CR1 |= 0x1<<13;//Enable UART1
	UART1_CR1 |= 0x1<<2;//Enable Receiver
	UART1_CR1 |= 0x1<<3;//Enable Transmitter
	UART1_BRR |= 0X683;//load 9600 bps 
}

void KM_UART1_outchar(unsigned char data)
{
	while(!(UART1_SR&0x1<<7))//wait until Transmitter empty
	{
		;
	}
	UART1_DR = data;//load data into data register
}

void KM_UART1_OutString(char str[])
{
	int i=0;
	for(;str[i];i++)
	{
		KM_UART1_outchar(str[i]);//character by chararcter sending data
	}
}
void UART6_OutDec(char str[])
{
	int i=0;
	for(;str[i];i++)
	{
		KM_UART1_outchar(str[i]);//character by chararcter sending data
	}
}
void UART6_OutHex(char str[])
{
	int i=0;
	for(;str[i];i++)
	{
		KM_UART1_outchar(str[i]);//character by chararcter sending data
	}
}

void UART6_OutOct(char str[])
{
	int i=0;
	for(;str[i];i++)
	{
		KM_UART1_outchar(str[i]);//character by chararcter sending data
	}
}

char *convert(unsigned int num, int base) 
{ 
		char Representation[]= "0123456789ABCDEF";
		char buffer[50]; 
		char *ptr; 
		ptr = &buffer[49]; 
		*ptr = '\0'; 
		do 
		{ 
			*--ptr = Representation[num%base]; 
			num /= base; 
		
		}while(num != 0); 
		return (ptr); 
}

void Myprintf(char* format,...) 
{ 
	char *traverse; 
	int i; 
	char *s; 
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, format); 
	for(traverse = format; *traverse != '\0'; traverse++) 
	{ 
			while( *traverse != '%' ) 
			{ 
				KM_UART1_outchar(*traverse);
				traverse++; 
			} 
			traverse++; 
			//Module 2: Fetching and executing arguments
			switch(*traverse) 
			{ 
				case 'c' : i = va_arg(arg,int); //Fetch char argument
					   KM_UART1_outchar(i);
					   break; 
				case 'd' : i = va_arg(arg,int); //Fetch Decimal/Integer argument
					   if(i<0)
					   { 
						i = -i;
						KM_UART1_outchar('-'); 
					   } 
					   UART6_OutDec(convert(i,10));
					   break; 
				case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
					  UART6_OutOct(convert(i,8));
					  break; 
				case 's': s = va_arg(arg,char *); //Fetch string
					  KM_UART1_OutString(s); 
					  break; 
				case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
					  UART6_OutHex(convert(i,16));
					  break; 
			}
		} 
	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
} 

int main() 
{ 
	UART1_MUX_init();
	KM_UART_init_cofig();
	Myprintf(" Kernel Masters %d %s %c %o %x",-90,"string nm",'c',25,4095);
	return 0;
}

