//Write a program to print below series
//1-(1/2!)+(1/3!)--------(1/n!)
#include<stdio.h>
int main()
{
	int n;
	float fact=1,series=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		fact*=i;
		if(i%2==0)
			series-=1/fact;
		else
			series+=1/fact;
	}
	printf("Results=%f\n",series);
}	
