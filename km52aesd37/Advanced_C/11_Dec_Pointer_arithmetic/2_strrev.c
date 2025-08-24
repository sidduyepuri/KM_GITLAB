//2)  char * strrev( char s[]); // returns string base address

#include<stdio.h>
#include<string.h>
char * strrev( char *);
int main()
{
	char str[20],*str2;
	scanf("%s",str);
	str2=strrev(str);
	printf("%s\n",str2);
	return 0;	
}
char *strrev(char *str)
{
	int i,j=strlen(str)-1,temp;
	for(i=0;i<j;i++,j--){
		temp=*(str+i);
		*(str+i)=*(str+j);
		*(str+j)=temp;
	}
	return str;
}

