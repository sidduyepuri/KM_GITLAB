//4. WAP to count the bits set (bit value 1 ) in an integer? Find out and compare different possibilities?

#include<stdio.h>
int set_count1(int x,int size);
int set_count(int x,int size);
int main()
{
	int n,i,count;
	printf("Enter value:");
	scanf("%d",&n);
	count=set_count(n,sizeof(n));
	printf("set count=%d\n",count);
	count=set_count1(n,sizeof(n));
	printf("set count=%d\n",count);
	return 0;
}
//possibility 1
int set_count(int x,int size)
{
	int i,count=0;
	for(i=0;i<size*8;i++)
	{
		if(x&(0x1<<(size*8-1)))
			count++;
		x=x<<1;
	}
	return count;
}
//possibility 2
int set_count1(int x,int size)
{
	int count=0;
	while(x>0)
	{
		x=x&(x-1);
		count++;
	}
	return count;
}
