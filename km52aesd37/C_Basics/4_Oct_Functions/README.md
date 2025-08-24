DATE: 04-OCT-2023 || TOPIC: FUNCTIONS With Declaration

Note: Program should compile with 0 warnings when compiled with –Wall option. -Wall will show any suppressed (hidden) warnings.
	eg.,, gcc -Wall 1.c  
1. Write a program with a function that takes two integer arguments, and prints all prime numbers between those numbers using the prime number function written above.return type should be void.
	PrintAllPrimes - return type is void. Should use IsPrime() function written yesterday.

2. Write a function that takes two numbers, a and n as input arguments and returns the value of a to the power of n,without using * operator

3. Calculate the salary of an employee for a given month and year, after deducting the salary for lose of pay days.
His total monthly salary, and number of days of Loss of Pay (LOP), & month & year are provided as input. Validate the negative cases like –ve salary, -ve date or –ve year in main, before calling other functions.
	Print the net salary in main function. 
	Read the below information and implement as per given file names and function names in each file.

Functions: Implement the below functions along with main
FileName: main.c
1) main function. takes input, calls calculatenetsalary function.

FileName: daysinmonth.c

2)int  NoOfDaysinMonth(int  m, int  y);
// returns the number of days in a month. call isleapyear function when you have to return number of days in february.

3)int  IsLeapYear(int   y);
// checks if a year is leap year or not.

FileName: calsal.c

4)int  CalculateNetSalary(int  total, int  lop, int  m, int  y); // calculates and returns the net salary for a given month & year  , uses  NoOfDaysinMonth to calculate the one day salary.
	calculate one day salary by deviding total salary with number of days in a month.
	deduct the salary for the lop days.
	return the remaining salary.

Declare all functions in a header file and include.


