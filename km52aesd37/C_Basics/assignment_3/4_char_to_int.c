/*Input 3 digits, read them into three different characters. Make one integer out of them and display.
	Eg., input 345.(stored as char c =‘3’,b=‘4’,d=‘5’.)
	Output : int i = 345. ( store 345 in integer i and print the value of i as output)
	hint: any digital character can be converted to a corresponding digit by subtraction with '0'.*/
#include<stdio.h>
int main()
{
	char a,b,c;
	scanf("%c %c %c",&a,&b,&c);
	int i=a-'0';
	i*=10;
	i+=b-'0';
	i*=10;
	i+=c-'0';
	printf("i=%d\n",i);
	return 0;
}
