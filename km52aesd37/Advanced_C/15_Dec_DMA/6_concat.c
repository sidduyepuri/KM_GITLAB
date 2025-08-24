/*6) Write a function, that takes two strings as input and concatenates only the first n characters from first string and first m characters from second string and makes a new string.
eg., input str1 = "kernel masters", str2 = "raayan systems", n = 3, m = 5
output : kerraaya		*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *concat(char *,char *);
int main()
{

	char *str1=(char *)malloc(20*sizeof(char));
	printf("input str1:");
	scanf("%[^\n]s",str1);
	char *str2=(char *)malloc(20*sizeof(char));
	printf("input str2:");
	scanf(" %[^\n]s",str2);
	char *str3=(char *)malloc(20*sizeof(char));
	str3=concat(str1,str2);
	printf("output:%s\n",str3);
}
char *concat(char *str1,char *str2)
{
	int n,m,i,j;
	printf("Enter n and m:");
	scanf("%d%d",&n,&m);
	char *str3=(char *)malloc(20*sizeof(char));
	strcpy(str3,str1);
	for(i=n,j=0;j<m;j++,i++)
	{
		str3[i]=str2[j];
	}
	str3[i]='\0';
	return str3;
}
