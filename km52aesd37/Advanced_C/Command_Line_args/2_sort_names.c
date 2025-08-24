//2   sorting a list of names received on command line argument, with options like -r and -i
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sorting(int (*cmp[])(const char*,const char*),char *str[],int n,int option,char *op,char *op1,char *argv[]);
int stricmp(const char *,const char *);
int main(int argc,char *argv[])
{
	int n,i,j;
	int (*cmp[])(const char *,const char *)={strcmp,stricmp};
	n=argc-1;
	printf("args=%d\n",n);
	char *str[n];
	for(i=0;i<n;i++)
	{
		str[i]=argv[i+1];
	}
	char *op="-r",*op1="-i";
	if((strcmp(argv[1],op)==0)&&(strcmp(argv[2],op1)==0))
	{
		sorting(cmp,str,n,1,op,op1,argv);
	}
	else if(strcmp(argv[1],op)==0)
	{
		sorting(cmp,str,n,0,op,op1,argv);
	}
	else if(strcmp(argv[1],op1)==0)
	{
		sorting(cmp,str,n,1,op,op1,argv);
	}
	else if((strcmp(argv[1],op)!=0)&&(strcmp(argv[2],op1)!=0))
		sorting(cmp,str,n,0,op,op1,argv);
}
void sorting(int (*cmp[])(const char*,const char*),char *str[],int n,int option,char *op,char *op1,char *argv[])
{
	int i,j;
	char *temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(argv[1],op)==0)
			{
				if(cmp[option](*(str+i),*(str+j))<0)
				{
					temp=str[i];
					str[i]=str[j];
					str[j]=temp;					
				}
			}
			else
			{
				if(cmp[option](*(str+i),*(str+j))>0)
				{
					temp=str[i];
					str[i]=str[j];
					str[j]=temp;					
				}
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
	if((*str1>=65&&*str1<=90)&&(*str2>=97&&*str2<=122))
		return ((*str1+32)-*str2);
	if((*str2>=65&&*str2<=90)&&(*str1>=97&&*str1<=122))
		return ((*str1-32)-*str2);
	else
		return (*str1-*str2);
}

