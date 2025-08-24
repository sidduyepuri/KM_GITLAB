//7) char  * strcat(char d[], char s[]); // returns destination base address

#include<stdio.h>
#include<string.h>
char *str_cat(char *str1,char *str2);
int main()
{
	char str1[50],str2[20],*str;
	scanf("%s%s",str1,str2);
	str=str_cat(str1,str2);
	printf("String1=%s\n",str);
	return 0;
}
char *str_cat(char *str1,char *str2)
{
	int i=strlen(str1),j;
	for(j=0;*(str2+j)!='\0';i++,j++){
		*(str1+i)=*(str2+j);
	}
	*(str1+i)='\0';
	return str1;
}

