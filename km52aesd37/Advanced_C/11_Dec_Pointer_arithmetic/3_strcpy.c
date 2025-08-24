//3) char * strcpy( char d[] , char s[]);  // returns destination base address

#include<stdio.h>
char *str_cpy(char str1[],char str2[]);
int main()
{
	char str1[30],str2[30],*str;
	scanf("%s",str2);
	str=str_cpy(str1,str2);
	printf("string1=%s\n",str);
	return 0;
}
char *str_cpy(char *str1,char *str2)
{
	int i=0;
	for(;*(str2+i)!='\0';i++){
		*(str1+i)=*(str2+i);
	}
	*(str1+i)='\0';
	return str1;
}

