/*Find the value of the below series upto n terms:
	1 + 1/2 + 1/3 + 1/4 .... 1/n
	1 - 1/2 + 1/3 - 1/4 .... 1/n
	1 - 1/2! + 1/3! - 1/4! .... 1/n
	9 + 99 + 999 + 9999 ....... upto n terms		*/
#include<stdio.h>
int main()
{
	int n,i=1,fact=1,sum4=0,temp=0;
	float sum1=0,sum2=0,sum3=0;
	scanf("%d",&n);
	while(i<=n)
	{
		//1 + 1/2 + 1/3 + 1/4 .... 1/n
		float j=i;
		sum1+=1/j;
		//1 - 1/2 + 1/3 - 1/4 .... 1/n
		float k=i;
		if(i%2==0)
			sum2-=1/k;
		else
			sum2+=1/k;
		//1 - 1/2! + 1/3! - 1/4! .... 1/n
		fact*=i;
		float l=fact;
		if(i%2==0)
			sum3-=1/l;
		else
			sum3+=1/l;
		//9 + 99 + 999 + 9999 ....... upto n terms
		temp=temp*10+9;
		sum4+=temp;
		
		i++;
	}
	printf("1 + 1/2 + 1/3 + 1/4 .... 1/n=%f\n",sum1);
	printf("1 - 1/2 + 1/3 - 1/4 .... 1/n=%f\n",sum2);
	printf("1 - 1/2! + 1/3! - 1/4! .... 1/n=%f\n",sum3);
	printf("9 + 99 + 999 + 9999 ....... upto n terms=%d\n",sum4);
	return 0;

}
