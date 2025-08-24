/*11) Write a function to replace a given substring by another string of same length in a given string, return the destination string base address.
	char * strreplacestr(char * str[], char *sub1[] , char *sub2[]);
	eg., input main string: Kernel Masters
	input substring: er
	input substring to replace: 12
	output: K12nel Mast12s				*/

#include<stdio.h>
#include<string.h>
char *strreplacestr(char *,char *,char *); 
int main()
{
	char str1[30],str2[30],rstr[10];
	printf("Enter string:");
	scanf("%[^\n]s",str1);
	printf("Enter sub string:");
	scanf("%s",str2);
	printf("Enter replace string:");
	scanf("%s",rstr);
	char *i=strreplacestr(str1,str2,rstr);
	printf("after replace string %s\n",i);
	return 0;
}
char *strreplacestr(char *str1,char *str2,char *rstr)
{
	int i,j=0,len=strlen(str2),ret,k,count=0;
	for(i=0;*(str1+i)!='\0';i++)
	{
		while(*(str1+i)==*(str2+j)&&*(str2+j)!='\0')
		{
			count++;
			i++;
			j++;
		}
		if(count==1)
			i--;
		if(*(str2+j)=='\0')
		{	
			ret=i-len,k=0;
			while(*(rstr+k)!='\0')
			{
				*(str1+ret)=*(rstr+k);
				ret++;
				k++;
			}
			i--;
		}
		count=0;
		j=0;
	}
	return str1;
}

