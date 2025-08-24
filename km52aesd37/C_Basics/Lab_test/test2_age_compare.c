//Read the DOB and compare and print which one older
#include<stdio.h>
int main()
{
	int d1,m1,y1,d2,m2,y2;
	scanf("%d-%d-%d,%d-%d-%d",&d1,&m1,&y1,&d2,&m2,&y2);
	if(y1>y2)
		printf("Person born on %d-%d-%d is older\n",d2,m2,y2);
	else if(y1<y2)
		printf("Person born on %d-%d-%d is older\n",d1,m1,y1);
	else if(m1>m2)
		printf("Person born on %d-%d-%d is older\n",d2,m2,y2);
	else if(m1<m2)
		printf("Person born on %d-%d-%d is older\n",d1,m1,y1);
	else if(d1>d2)
		printf("Person born on %d-%d-%d is older\n",d2,m2,y2);
	else if(d1<d2)
		printf("Person born on %d-%d-%d is older\n",d1,m1,y1);
	else
		printf("Both are of same age\n");
	return 0;
}
