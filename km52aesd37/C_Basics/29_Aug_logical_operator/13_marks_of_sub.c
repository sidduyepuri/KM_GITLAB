/*Find the % of marks for 6 subjects (read 6 subject marks and calculate percentage), for a student, and print the grade of the student as per below division , using if else statement and typecasting operator to get perfect floating point percentage.
	80 - 100        : Honours
	60 - 79         : First Division
	50 - 59         : Second Division
	40 - 49         : Third Division
	0 - 39          : Fail
*/
#include<stdio.h>
int main()
{
	float s1,s2,s3,s4,s5,s6;
	float per;
	scanf("%f%f%f%f%f%f",&s1,&s2,&s3,&s4,&s5,&s6);
	per=(s1+s2+s3+s4+s5+s6)/6;
	if (per<=100 && per>=80)
		printf("Honors\n");
	else if (per<80 && per>=60)
		printf("First division\n");
	else if (per<60 && per>=50)
		printf("Second division\n");
	else if (per<50 && per>=40)
		printf("Third division\n");
	else
		printf("Fail\n");
}
