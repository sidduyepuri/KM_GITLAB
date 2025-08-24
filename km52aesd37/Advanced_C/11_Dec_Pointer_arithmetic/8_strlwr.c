//8) char * strlwr(char s[]); // returns s base address

#include<stdio.h>
char * strlwr(char s[]);
int main()
{
	char str[20],*str1;
	scanf("%s",str);
	str1=strlwr(str);
	printf("%s\n",str1);
	return 0;
}
char * strlwr(char *str)
{
	int i;
	for(i=0;*(str+i)!='\0';i++){
		if(*(str+i)<='Z'&&*(str+i)>='A')
			*(str+i)=*(str+i)+32;
	}
	return str;
}
