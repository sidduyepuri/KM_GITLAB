/*3). Write a program to replace a given character by another character in a string.
	" WAP to display the word expansion of a number
	eg., Input : 789
	Output : Seven Eight Nine"	*/
#include<stdio.h>
void expansion(char str[]);
int main()
{
	char str[10];
	printf("Enter a string:");
	scanf("%s",str);
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		switch(str[i]){
		case '0': printf("One "); break;
		case '1': printf("One "); break;
		case '2': printf("Two "); break;
		case '3': printf("Three "); break;
		case '4': printf("Four "); break;
		case '5': printf("Five "); break;
		case '6': printf("Six "); break;
		case '7': printf("Seven "); break;
		case '8': printf("Eight "); break;
		case '9': printf("Nine "); break;
		}
	}
	printf("\n");
	return 0;
}
