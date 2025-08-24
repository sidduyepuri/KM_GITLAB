#include<stdio.h>
#include<stdlib.h>
int *fun(int);
int main()
{
	int n;
	scanf("%d",&n);
	int *p=fun(n);
	printf("p=%p,&p=%p\n",p,&p);
	free(p);
}

int *fun(int n)
{	
	int *p;
	p=(int *)malloc(n*sizeof(int));
	if(p==NULL)
	{
		printf("memory not sufficient\n");
		return 0;
	}
	else
		return p;
}
