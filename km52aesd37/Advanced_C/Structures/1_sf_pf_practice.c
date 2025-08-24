/*1) Practice scanf and printf on each member of the structure using a structure variable using the below structure template:

	struct student	
	{
	int ID;
	char name[50];
	int marks[6];
	int d,m,y;
	float per;
	char gender
	};	
create a structure variable of the above type and read ID , name and marks of 6 subjects, date of birth and date of joining using scanf and printf.
Then calculate the percentage of marks, and store the percentage using per pointer member, and print it.Write a function to calculate the percentage ,and update the percentage member of the structure using function (send only per member using call by reference).		*/
#include "struct.h"
float percentage(int marks[],int n);
int main()
{
	struct student s1;
	printf("Enter ID and name:");
	scanf("%d %s",&s1.ID,s1.name);
	int i,sum=0;
	printf("Enter 6 subjects marks:");
	for(i=0;i<6;i++){
		scanf("%d",&s1.marks[i]);
	}
	printf("Enter DOB:");
	scanf("%d%d%d",&s1.d,&s1.m,&s1.y);
	s1.per=percentage(s1.marks,6);
	printf("student ID:%d\n",s1.ID);
	printf("student name:%s\n",s1.name);
	printf("date of birth:%d-%d-%d\n",s1.d,s1.m,s1.y);
	printf("percentage:%f\n",s1.per);
}
float percentage(int marks[],int n)
{
	int i;
	float per,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=marks[i];
	}
	per=(sum/n);
	return per;
}

