//2) Create an array of structures using the above template. read the data for all elements of the array. and print the topper name with the highest percentage. 
#include "struct.h"
int main()
{
	int n,i,j;
	float percent,sum=0;
	char *nm;
	printf("Enter no of. students:");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
		printf("Enter student%d ID:",i+1);
		scanf("%d",&s[i].ID);
		printf("Enter student%d name:",i+1);
		scanf("%s",s[i].name);
		printf("Enter student%d 6 subjects marks:",i+1);
		for(j=0;j<6;j++)
		{
			scanf("%d",&s[i].marks[j]);
			sum+=s[i].marks[j];
		}
		s[i].per=sum/6;
		if(i>0)
		{
			if(s[i].per>s[i-1].per){
				percent=s[i].per;
				nm=s[i].name;
			}
		}
		else{
			percent=s[i].per;
			nm=s[i].name;
		}
		sum=0;
		printf("Enter student%d DOB:",i+1);
		scanf("%d-%d-%d",&s[i].d,&s[i].m,&s[i].y);
		printf("Enter student%d gender:",i+1);
		scanf(" %c",&s[i].gender);
	}
	printf("Topper name:%s\n",nm);
	printf("Topper percentage:%f\n",percent);
}
