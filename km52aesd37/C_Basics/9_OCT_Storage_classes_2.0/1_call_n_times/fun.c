#include<stdio.h>
void fun()
{
	static int s;
	s++;
	if(s==1||s>20&&s%10==1)
		printf("Iam called %dst time\n",s);
	else if(s==2||s>20&&s%10==2)
		printf("Iam called %dnd time\n",s);
	else if(s==3||s>20&&s%10==3)
		printf("Iam called %drd time\n",s);
	else
		printf("Iam called %dth time\n",s);
}
