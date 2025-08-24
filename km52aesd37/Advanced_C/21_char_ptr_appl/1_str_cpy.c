/*1) Implement your own string copy function.
try calling the string copy function by sending the below as input:
1) string constant as destination and string variable as source
2) string variable as destination and string constant as source
3) string variable as destination and string variable as source
4) string constant as destination and string constant as source
  note down the output and analyze the reasons.			*/
#include<stdio.h>
char *str_cpy1(const char str1[],char str2[]);
char *str_cpy2(char str1[],const char str2[]);
char *str_cpy3(char str1[],char str2[]);
char *str_cpy4(const char str1[],const char str2[]);
int main()
{
	char *str1="kernel";
	char *str2="masters";
	char *str;
//	str=str_cpy1(str1,str2);
//	str=str_cpy2(str1,str2);
//	str=str_cpy3(str1,str2);
//	str=str_cpy4(str1,str2);
	printf("%s\n",str);
	return 0;
}
/*char *str_cpy1(const char *str1,char str2[])
{
	int i=0;
	for(;*(str2+i)!='\0';i++)
	{
		*(str1+i)=str2[i];
	}
	*(str1+i)='\0';
	return str1;
}
//Segmentation fault (core dumped)	
char *str_cpy2(char str1[],const char *str2)
{
	int i=0;
	for(;*(str2+i)!='\0';i++)
	{
		*(str1+i)=str2[i];
	}
	*(str1+i)='\0';
	return str1;
}*/
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
/*char *str_cpy4(const char *str1,const char *str2)
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
//Segmentation fault (core dumped)
