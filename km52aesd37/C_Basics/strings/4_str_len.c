/*4). "Write a program to find the length of a string. Length is the number of characters in a string (null character is not counted).
eg., char name[10] = ""abc""; //size of name is 10 bytes
            // length of name is 3"		*/
#include<stdio.h>
int main()
{
	char str[10];
	scanf("%s",str);
	int i,len=0;
	for(i=0;str[i]!=0;i++)
		len++;
	printf("Lenth of the string is %d\n",len);
	return 0;
}

