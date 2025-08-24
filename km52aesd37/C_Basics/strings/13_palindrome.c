//2). Write a program that reads a string as input, and determines whether the string is a palindrome or not.

#include<stdio.h>
#include<string.h>
int palindrome(char str[]);
int main()
{
	char str[100];
	scanf("%s",str);
	int n=palindrome(str);
	if(n==1)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
	return 0;
}
int palindrome(char str[])
{
	int i,j;
	int len=strlen(str);
	for(i=0,j=len-1;i<j;i++,j--){
			if(str[i]!=str[j])
				return 0;
	}
	return 1;
}

