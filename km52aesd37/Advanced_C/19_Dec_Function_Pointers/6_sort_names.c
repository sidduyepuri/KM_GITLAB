/*
6) sorting a list of names received from the keyboard, with options using callback functions.
1 :  sort with case sensitivity (strcmp)
2 : sort without case sensitivity (stricmp)
*/
#include<stdio.h>
#include<string.h>
void sorting(int (*cmp[])(const char*,const char*),char str[][20],int n,int option);
int main()
{

	int n,i,j;
	int stricmp(const char *,const char *);
	scanf("%d",&n);
	char str[n][20];
	int (*cmp[])(const char *,const char *)={strcmp,stricmp};
	for(i=0;i<n;i++)
	{
		scanf("%s",*(str+i));
	}
	printf("options:\n1.sort with case sensitivity (strcmp)\n2.sort without case sensitivity (stricmp)\nEnter your option:");
	int option;
	scanf("%d",&option);
	option=option-1;
	sorting(cmp,str,n,option);
	return 0;
}
void sorting(int (*cmp[])(const char*,const char*),char str[][20],int n,int option)
{
	int i,j;
	char temp[20];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(cmp[option](*(str+i),*(str+j))>0)
			{
				strcpy(temp,*(str+i));
				strcpy(*(str+i),*(str+j));
				strcpy(*(str+j),temp);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s\n",*(str+i));
	}
}
int stricmp(const char *str1,const char *str2)
{
	while((*str1==*str2)||(*str1+32==*str2)||(*str1==*str2-32)||(*str1==*str2+32)||(*str1-32==*str2))
	{
		if(*str1=='\0'&&*str2=='\0')
			return 0;
		str1++;
		str2++;
	}
	return (*str1-*str2);
}

