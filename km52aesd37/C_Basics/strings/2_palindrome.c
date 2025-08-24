//2). Write a program that reads a string as input, and determines whether the string is a palindrome or not.

#include<stdio.h>
#include<string.h>
void palindrome(char str[]);
int main()
{
	char str[100];
	scanf("%s",str);
	palindrome(str);
	return 0;
}
void palindrome(char str[])
{
	int flag=0,i,j;
	int len=strlen(str);
	for(i=0,j=len-1;i<j;i++,j--){
			if(str[i]!=str[j]){
				printf("Not a palindrome\n");
				flag=1;
				break;
			}
	}
	if(flag==0)
		printf("Palindrome\n");
}

