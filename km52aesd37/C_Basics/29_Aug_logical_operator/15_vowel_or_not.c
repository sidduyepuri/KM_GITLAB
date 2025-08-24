//Read a character and print if it is vowel or not.
#include<stdio.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
		printf("Vowel\n");
	else
		printf("not an Vowel\n");
}
