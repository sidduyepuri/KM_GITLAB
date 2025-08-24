/*8) Write a function to determine if a character is alphanumeric or not and print the appropriate output in main function. (return 1 if it is alphanumeric, 0 if it is not alpha numeric).
	Hint: int fun_alpha_num(char c).	*/
#include<stdio.h>
int fun_alpha_num(char c)
{
	if(c<='z'&&c>='a'||c<='Z'&&c>='A'||c<='9'&&c>='0')
		return 1;
	else
		return 0;
}
int main()
{
	char c;
	scanf("%c",&c);
	if(fun_alpha_num(c)==1)
		printf("It is a alpha numeric\n");
	else
		printf("Not an alpha numeric\n");
	return 0;
}
