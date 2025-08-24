//4) Write a swap function to swap the values of two character variables.
#include<stdio.h>
void swap(char ch1,char ch2);
int main()
{
	char ch1='a';
	char ch2='b';
	swap(ch1,ch2);
	return 0; 
}
void swap(char ch1,char ch2)
{
	char temp;
	temp=ch1;
	ch1=ch2;
	ch2=temp;
	printf("ch1=%c ch2=%c\n",ch1,ch2);
}
