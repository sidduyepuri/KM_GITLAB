/* read the 6 subject scores of n students, calculate their percentage, and print the grade of each student based on % using below slabs:
	80 - 100        : Honours
	60 - 79         : First Division
	50 - 59         : Second Division
	40 - 49         : Third Division
	0 - 39          : Fail	*/
#include<stdio.h>
int main()
{
	int i=1,n;
	scanf("%d",&n);
	while(i<=n)
	{
		int s1,s2,s3,s4,s5,s6;
		float per;
		scanf("%d%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5,&s6);
		per=(s1+s2+s3+s4+s5+s6)/6.0;
		if(per<=100 && per>=80)
			printf("Honours\n");
		else if(per<=79 && per>=60)
			printf("First Division\n");
		else if(per<=59 && per>=50)
			printf("Second Division\n");
		else if(per<=49 && per>=40)
			printf("Third division\n");
		else
			printf("Fail\n");
		i++;
	}
	return 0;
}
