/*Write a function that takes two strings as input and creates and returns a new string with the alternately mixed characters from both, both strings may not be same lenth, add extra characters at the end. Use dynamic memory allocation to create the new string.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *new_str(char *,char *);
int main()
{
	char *str1=(char *)malloc(20*sizeof(char));
	char *str2=(char *)malloc(20*sizeof(char));
	printf("Enter string1:");
	scanf("%s",str1);
	printf("Enter string2:");
	scanf(" %s",str2);
	char *str3=(char *)malloc(40*sizeof(char));
	str3=new_str(str1,str2);
	printf("new string:%s\n",str3);
	return 0;
}
char *new_str(char *str1,char *str2)
{
	int i,l=0,m=0;
	int j=strlen(str1);
	int k=strlen(str2);
	char *str3=(char *)malloc(40*sizeof(char));
	for(i=0;i<(j+k);i++)
	{
		if(*(str1+l)!='\0')
		{	
			str3[i]=str1[l];
			l++;
			if(*(str2+m)!='\0')
				i++;
		}
		if(*(str2+m)!='\0')
		{	
			str3[i]=str2[m];
			m++;
		}
	}
	str3[i]='\0';
	return str3;
}

