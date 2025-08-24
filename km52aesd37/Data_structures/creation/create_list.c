#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
	int ID;
	char name[10];
	struct student *next;
}stu;

stu *traversal(stu *T)
{
	while(T)
	{
		printf("ID:%d name:%s\n",T->ID,T->name);
		T=T->next;
	}
}

stu *createnode()
{
	stu *N=malloc(sizeof(stu));
	printf("Enter id and name:");
	scanf("%d%s",&N->ID,N->name);
	N->next=NULL;
	return N;
}

stu *createlist()
{
	stu *H=NULL,*N=NULL,*L=NULL;
	char ch='y';
	while(ch == 'y')
	{
		N=createnode();
		if(H==NULL)
			H=N;
		else
			L->next=N;
		L=N;
		printf("Create another? (y/n)");
		scanf(" %c",&ch);
	}
	return H;
}


int main()
{
	stu *H;
	H=createlist();
	traversal(H);
	return 0;
}
