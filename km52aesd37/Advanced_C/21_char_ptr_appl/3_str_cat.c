/*3) Implement your own string concatenation function.
try calling the string copy function by sending the below as input:
1) string constant as destination and string variable as source
2) string variable as destination and string constant as source
3) string variable as destination and string variable as source
4) string constant as destination and string constant as source
note down the output and analyze the reasons.	*/
#include<stdio.h>
#include<string.h>
char *str_cat(char *str1,char *str2);
char *str_cpy1(const char *str1,char str2[]);
char *str_cpy2(char str1[],const char *str2);
char *str_cpy3(char str1[],char str2[]);
char *str_cpy4(const char *str1,const char *str2);
int main()
{
	char str1[]="Kernel";
	char str2[]="Masters"
	char *str;
	str=str_cat(str1,str2);
	printf("String1=%s\n",str);
	return 0;
}
char *str_cat(char *str1,char *str2)
{
	char *str;
	str=str_cpy1(str1,str2);
	return str;
}
char *str_cpy1(const char *str1,char str2[])
{
	int i=strlen(str1),j;
	for(;*(str2+i)!='\0';i++)
	{
		*(str1+i)=str2[i];
	}
	*(str1+i)='\0';
	return str1;
}
//Segmentation fault (core dumped)	
/*char *str_cpy2(char *str1,const char *str2)
{
	int i=strlen(str1),j=0;
	for(;str2[j]!='\0';i++,j++)
	{
		str1[i]=str2[j];
	}
	str1[i]='\0';
	return str1;
}
char *str_cpy3(char str1[],char str2[])
{
	int i=0;
	for(;*(str2+i)!='\0';i++)
	{
		str1[i]=str2[i];
	}
	*(str1+i)='\0';
	return str1;
}
char *str_cpy4(const char *str1,const char *str2)
{
	int i=0;
	for(;*(str2+i)!='\0';i++)
	{
		*(str1+i)=str2[i];
	}
	*(str1+i)='\0';
	return str1;
	return str1;
}*/

