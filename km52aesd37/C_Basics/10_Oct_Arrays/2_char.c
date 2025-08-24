/*2 Write the following program :
Declare a character array without size.
Initialize the array with characters of your name.
Print your name using for loop.			*/
#include<stdio.h>
int main()
{
	char arr[]={'s','i','d','d','u'};
	int i;
	for(i=0;i<5;i++)
		printf("%c",arr[i]);
	printf("\n");
	return 0;
}

