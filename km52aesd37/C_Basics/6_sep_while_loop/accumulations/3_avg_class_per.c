//read the 6 subject scores of n students, calculate their percentage, and print the topper percentage. Print the average class percentage.
#include<stdio.h>
int main()
{
	int i=1,n,tp=0,avg,class=0;
	scanf("%d",&n);
	while(i<=n)
	{
		int s1,s2,s3,s4,s5,s6,per;
		scanf("%d%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5,&s6);
		per=(s1+s2+s3+s4+s5+s6)/6;
		class+=per;
		if(per>tp)
		{
			tp=per;
		}
		i++;
	}
	avg=class/n;
	printf("topper percentage=%d\n",tp);
	printf("average class percentage=%d\n",avg);
	return 0;
}
