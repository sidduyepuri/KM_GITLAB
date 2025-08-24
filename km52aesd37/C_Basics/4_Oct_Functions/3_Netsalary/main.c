/*3) Calculate the salary of an employee for a given month and year, after deducting the salary for lose of pay days.
His total monthly salary, and number of days of Loss of Pay (LOP), & month & year are provided as input. Validate the negative cases like –ve salary, -ve date or –ve year in main, before calling other functions.
	Print the net salary in main function. 
Read the below information and implement as per given file names and function names in each file.
Functions: Implement the below functions along with main
FileName: main.c
1)       main function. takes input, calls calculatenetsalary function.
FileName: daysinmonth.c
2)int  NoOfDaysinMonth(int  m, int  y);
// returns the number of days in a month. call isleapyear function when you have to return number of days in february.
3)int  IsLeapYear(int   y);
// checks if a year is leap year or not.
FileName: calsal.c
4)int  CalculateNetSalary(int  total, int  lop, int  m, int  y); // calculates and returns the net salary for a given month & year  , uses  NoOfDaysinMonth to calculate the one day salary.
calculate one day salary by deviding total salary with number of days in a month.
deduct the salary for the lop days.
return the remaining salary.				*/
#include<stdio.h>
#include"calsal.h"
int main()
{
	int tot_sal,lop,m,y,netsalary;
	printf("Enter Salary:");
	scanf("%d",&tot_sal);
	printf("Enter No of LOP's:");
	scanf("%d",&lop);
	printf("Month:");
	scanf("%d",&m);
	printf("Year:");
	scanf("%d",&y);
	if(tot_sal<0||lop<0||m<0||y<0){
		printf("Negative values are not validate\n");
		return -1; // ERROR HANDLING
	}
	netsalary=CalculateNetSalary(tot_sal,lop,m,y);
	printf("Net salary in this month:%d\n",netsalary);
	return 0;// SUCCESS
}
