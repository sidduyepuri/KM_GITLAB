//Read two numbers from the user ,and print the older date.
#include<stdio.h>
int main()
{
	int n,d1,m1,y1,d2,m2,y2;
	scanf("%d",&n);
	printf("Enter DOB of student 1:");
	scanf("%d%d%d",&d1,&m1,&y1);
	for(int i=1;i<n;i++)
	{
		printf("Enter DOB of student %d:",i+1);
		scanf("%d%d%d",&d2,&m2,&y2);
		if(y1<y2 || y1==y2 && m1<m2 || y1==y2 && m1==m2 && d1<d2)
				d1=d2,m1=m2,y1=y2;
	}
	printf("The youngest person is born in:%d-%d-%d\n",d1,m1,y1);
	return 0;
}
