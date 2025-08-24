//4) int  strcmp (char s1[], char s2[]);
#include<stdio.h>
#include<string.h>
int str_compare(char str1[],char str2[]);
int main()
{
	char str1[10],str2[10];
	scanf("%s%s",str1,str2);
	int i=str_compare(str1,str2);
	if(i==0)
		printf("Both strings same\n");
	else if(i>0)
		printf("Not same,string1 is bigger\n");
	else if(i<0)
		printf("Not same,string2 is bigger\n");
	return 0;
}
int str_compare(char *str1,char *str2)
{
	while((*str1==*str2)||(*str1+32==*str2)||(*str1==*str2-32)||(*str1==*str2+32)||(*str1-32==*str2))
	{
		if(*str1=='\0'&&*str2=='\0')
			return 0;
		str1++;
		str2++;
	}
	return (*str1-*str2);
}
			
	
