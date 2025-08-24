/*Extend the percentage marks program to print the grade of the student as per below division , using switch statement.
	80 - 100        : Honours
	60 - 79         : First Division
	50 - 59         : Second Division
	40 - 49         : Third Division
	0 - 39          : Fail	*/
#include<stdio.h>
int main()
{
	int per;
	scanf("%d",&per);
	switch(per)
	{
		case 80 ... 100: printf("Honours\n");
				 break;
		case 60 ... 79: printf("First Division\n");
				 break;
		case 50 ... 59: printf("Second Division\n");
				 break;
		case 40 ... 49: printf("Third Division\n");
				 break;
		case 0 ... 39: printf("Fail\n");
				 break;
		default : printf("Invalid\n");

	}
	return 0;
}
