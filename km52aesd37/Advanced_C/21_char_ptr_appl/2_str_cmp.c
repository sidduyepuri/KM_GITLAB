//2) Implement your own string comparison function and try calling the function using two string constants as input arguments.
#include<stdio.h>
#include<string.h>
int str_compare(const char *str1,const char *str2);
int main()
{
	char *str1="Siddu",*str2="siddu";
	int i=str_compare(str1,str2);
	if(i==0)
		printf("Both strings same\n");
	else if(i>0)
		printf("Not same,string1 is bigger\n");
	else if(i<0)
		printf("Not same,string2 is bigger\n");
	return 0;
}
int str_compare(const char *str1,const char *str2)
{
	while(*str1==*str2)
	{
		if(*str1=='\0'&&*str2=='\0')
			return 0;
		str1++;
		str2++;
	}
	return (*str1-*str2);
}

