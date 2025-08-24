#include<stdio.h>
void PrintSubscript(int);
void PrintMonthName(int);
void PrintDateinFormat(int d2,int m2,int y2)
{
	printf("The candidate born on %d",d2);
	PrintSubscript(d2);
	PrintMonthName(m2);
	printf("-%d is elder of all\n",y2);
}
void PrintSubscript(int d2)
{
	if(d2==1||d2==21||d2==31)
		printf("st ");
	else if(d2==2||d2==22)
		printf("nd ");
	else if(d2==3||d2==23)
		printf("rd ");
	else
		printf("th ");
}
void PrintMonthName(int m2)
{
	switch(m2)
	{
		case 1: printf("January"); break;
		case 2: printf("February"); break;
		case 3: printf("March"); break;
		case 4: printf("April"); break;
		case 5: printf("May"); break;
		case 6: printf("June"); break;
		case 7: printf("July"); break;
		case 8: printf("August"); break;
		case 9: printf("September"); break;
		case 10: printf("October"); break;
		case 11: printf("November"); break;
		case 12: printf("December"); break;
	}
}
