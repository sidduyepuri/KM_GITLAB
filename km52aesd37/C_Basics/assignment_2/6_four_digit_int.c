/*Read a 4 digit integer into a variable, using scanf and print it in the below format using escape sequences.
		eg., input: 3467*/
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\b\b\b   \n%d\b\b  \n%d\b \n%d\n",n,n,n,n);
	printf("%d\b\b\b   \n%d\b\b  \b\b\b\b \n%d\b \b\b\b\b  \n%d\b\b\b\b\b   \n",n,n,n,n);
	return 0;	
}
