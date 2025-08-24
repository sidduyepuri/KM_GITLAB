//10) char * strstr(char str[], char sub[]); //returns the address of the character in the main string from where the substring is matching.

#include<stdio.h>
#include<string.h>
char *str_str(char *,char *); 
int main()
{
	char str1[20],str2[20];
	printf("Enter string:");
	scanf("%[^\n]s",str1);
	printf("Enter sub string:");
	scanf("%s",str2);
	char *i=str_str(str1,str2);
	if(str1!=i)
	{
		printf("starting address %p\n",str1);
		printf("sub string found address %p\n",i);
	}
	else
		printf("sub string not found\n");
	return 0;
}
char *str_str(char *str1,char *str2)
{
	int i=0,j=0,len=strlen(str2);
	for(;*(str1+i)!='\0'&&*(str2+j)!='\0';)
	{
		
		if(*(str1+i)!=*(str2+j)){
			i++;
			j=0;
		}
		else
		{
			i++;
			j++;
		}	
	}
	if(*(str2+j)=='\0')
	{
		str1=(str1+i)-len;
	}
	return str1;
}

