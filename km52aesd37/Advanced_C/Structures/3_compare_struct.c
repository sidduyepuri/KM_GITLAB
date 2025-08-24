//3) Write a function to compare 2 structures and return 1 if they are equal, and 0 if they are not equal.
#include "struct.h"
#include<string.h>
int compare_struct(struct student s1,struct student s2);
int main()
{
	int res;
	struct student s1={.ID=37,.name="sidu",.d=12,.m=10,.y=2002,.gender='m'};
	struct student s2={.ID=37,.name="siddu",.d=12,.m=10,.y=2002,.gender='m'};
	res=compare_struct(s1,s2);
	if(res!=0)
		printf("Both structures equal\n");
	else
		printf("Not equal\n");
	
}
int compare_struct(struct student s1,struct student s2)
{
	if(s1.ID!=s2.ID)
		return 0;
	if(strcmp(s1.name,s2.name)!=0)
		return 0;
	if(s1.d!=s2.d&&s1.m!=s2.m&&s1.y!=s2.y)
		return 0;
	if(s1.gender!=s2.gender)
		return 0;
	return 1;
}

