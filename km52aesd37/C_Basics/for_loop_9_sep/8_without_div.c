/*Write a program to find the quotient and reminder of two given numbers upon division, without using / and % operators considering negative and positive operands.
	Hint: Division is continuous subtraction until the reminder is smaller than the devisor.*/
#include<stdio.h>
int main()
{
	int a,b,rem=0,quoe=0;
	scanf("%d%d",&a,&b);
	for(;a>0&&b>0;)
	{
		if(a>=b){
			a=a-b;
			quoe++;
		}
		else
			break;
	}
	for(;a>0&&b<0;)
	{
		if(a>=-b){
			a=a+b;
			quoe++;
		}
		else
			break;
	}
	for(;a<0&&b>0;)
	{
		if(-a>=b){
			a=a+b;
			quoe++;
		}
		else
			break;
	}
	for(;a<0&&b<0;)
	{
		if(a<=b){
			a=a-b;
			quoe-=1;
		}
		else
			break;
	}
	rem=a;
	printf("Quotient=%d\n",quoe);
	printf("Remainder=%d\n",rem);
	return 0;

}
