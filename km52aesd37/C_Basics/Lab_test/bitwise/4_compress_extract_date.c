#include<stdio.h>
int ToDate(unsigned short int,unsigned short int,short int);
void printbinary(short int);
int ExtractMonth(unsigned short int);
int ExtractDate(unsigned short int);
int ExtractYear(unsigned short int);
int main()
{
	unsigned short int d,m,y;
	printf("Enter date:");
	scanf("%hd%hd%hd",&d,&m,&y);
	unsigned short int compress=ToDate(d,m,y);
	printbinary(compress);
	d=ExtractDate(compress);
	m=ExtractMonth(compress);
	y=ExtractYear(compress);
	printf("Extracted date:%hd-%hd-%hd\n",d,m,y);
	return 0;
}
int ToDate(unsigned short int d,unsigned short int m,short int y)
{
	unsigned short int x=0;
	y=y%100;
	m=m<<12;
	d=d<<7;
	x=y|m|d;	
	return x;
}
void printbinary(short int num)
{
	int i;
	for(i=0;i<16;i++){
		if(num&0x8000)
			printf("1");
		else
			printf("0");
		num=num<<1;
	}
	printf("\n");
}
int ExtractDate(unsigned short int d)
{
	d=(d<<4);
	d=d>>11;
	return d;
}
int ExtractMonth(unsigned short int m)
{
	m=m>>12;
	return m;
}
int ExtractYear(unsigned short int y)
{
	y=(y<<9);
	y=y>>9;
	return y;
}
