/*2).Read a main string, a character and a substring. Write a function that replaces every occurance of the character in the main string, by the given string and returns the new string as output. Use Dynamic memory allocation to create the new string
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *new_string(char *,char ,char *);
int main()
{
	char *str1=(char *)malloc(20*sizeof(char));
	char *str2=(char *)malloc(20*sizeof(char));
	char *str3=(char *)malloc(40*sizeof(char));
	char ch;
	printf("Enter main string:");
	scanf("%s",str1);
	printf("Enter character:");
	scanf(" %c",&ch);
	printf("Enter replace string:");
	scanf(" %s",str2);
	str3=new_string(str1,ch,str2);
	printf("new string:%s\n",str3);
	return 0;
}
char *new_string(char *str1,char ch,char *str2)
{
	int i,j,k=0;
	int s1=strlen(str1);
	int s2=strlen(str2);
	char *str3=(char *)malloc(40*sizeof(char));
	for(i=0;*(str1+i)!='\0';i++)
	{
		if(*(str1+i)==ch)
		{
			strcat(str3,str2);
			k+=s2;
		}
		else
		{	
			str3[k]=str1[i];
			k++;
		}
	}
	str3[k]='\0';
	return str3;
}


