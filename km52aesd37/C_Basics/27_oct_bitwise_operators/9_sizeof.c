//9. WAP to implement the sizeof operation using the bitwise operator.  
#include<stdio.h>
int main()
{
	int a,count=0,size;
	scanf("%d",&a);
	a=~(a&0);
	while(a){
		count++;
		a=a<<1;
	}	
	size=count/8;
	printf("size=%d\n",size);
	return 0;
}	
