//5) Write a function to take an array of structures as arguments, and convert all their names into capital letters( strupr implementation). print the data in the main function.
#include "struct.h"
void names_upr(char str[],int n);
int main()
{
	int n,i,j,sum=0;
	printf("Enter no of. students:");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
		printf("Enter student%d ID:",i+1);
		scanf("%d",&s[i].ID);
		printf("Enter student%d name:",i+1);
		scanf("%s",s[i].name);
	}
	for(i=0;i<n;i++)
	{
		names_upr(s[i].name,n);
		printf("name%d:%s\n",i+1,s[i].name);
	}
}
void names_upr(char  str[],int n)
{
	int i,j;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>=97&&str[i]<=122)
			str[i]=str[i]-32;
	}
}
