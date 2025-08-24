//1) create an integer dynamically ,read and print its value.

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr=(int *)malloc(sizeof(int));
	scanf("%d",ptr);
	printf("%d\n",*ptr);
}
