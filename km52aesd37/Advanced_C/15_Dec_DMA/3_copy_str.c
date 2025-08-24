//3) create a string dynamically, copy a string constant to it ( "Kernel"). Create another string dynamically. Copy the first string to second string.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *str1=(char *)malloc(5*sizeof(char));
	strcpy(str1,"Kernel");
	printf("%s\n",str1);
	char *str2=(char *)malloc(5*sizeof(char));
	strcpy(str2,str1);
	printf("%s\n",str2);
}
