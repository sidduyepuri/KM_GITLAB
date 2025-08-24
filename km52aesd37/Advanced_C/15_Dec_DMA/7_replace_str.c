/*7)Write a function that takes a main string and two sub strings (need not be same length), and replace every occurrence of first substring with the second substring in main string and return a new string as output.

eg., input : kernel  e   xxx

output: kxxxrnxxxl		*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *strreplacestr(char *,char *,char *); 
int main()
{
	char *str1=(char *)malloc(10*1);
	char *str2=(char *)malloc(10*1);
	char *rstr=(char *)malloc(10*1);
	printf("Enter string:");
	scanf("%[^\n]s",str1);
	printf("Enter sub string:");
	scanf(" %s",str2);
	printf("Enter replace string:");
	scanf(" %s",rstr);
	char *str3=strreplacestr(str1,str2,rstr);
	printf("after replace string %s\n",str3);
	return 0;
}
char *strreplacestr(char *str1,char *str2,char *rstr)
{
	int i,k=0,s1=strlen(str1),s2=strlen(str2),rs=strlen(rstr);
	char *res=(char *)malloc(30*1);
	for(i=0;*(str1+i)!='\0';i++)
	{
		if(strncmp(str1+i,str2,s2)==0)
		{
			strcat(res,rstr);
			k+=rs;
		}
		else{
			res[k]=str1[i];
			k++;
		}
	}
	return res;
}

