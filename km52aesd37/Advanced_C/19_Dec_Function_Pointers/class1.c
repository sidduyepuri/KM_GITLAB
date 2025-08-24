#include<stdio.h>
#include<string.h>

int main()
{
	int add(int,int);
	int (*p)(int,int)=&add;
	char * (*q)(char *,char *)=strcat;
	char str1[20]="Kernel",str2[20]="Masters";
	char *str=q(str1,str2);
	printf("%s",str);
	int a=10,b=20;
	int c=p(a,b);
	printf("Add=%d\n",c);
	int d=add(a,b);
	printf("Add=%d\n",d);
}

int add(int a ,int b)
{
	return a+b;
}
