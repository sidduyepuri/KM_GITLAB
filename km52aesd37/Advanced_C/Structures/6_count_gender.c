//6) Count and print how many girls and how many boys there are in the class.
#include "struct.h"
int main()
{
	int n,i,j,sum=0,count=0;
	printf("Enter no of. students:");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
		printf("Enter student%d name:",i+1);
		scanf("%s",s[i].name);
		printf("Enter student%d gender:",i+1);
		scanf(" %c",&s[i].gender);
		if(s[i].gender=='m')
			count++;
	}
	printf("No of Boys:%d\n",count);
	printf("No of Girls:%d\n",n-count);
}
