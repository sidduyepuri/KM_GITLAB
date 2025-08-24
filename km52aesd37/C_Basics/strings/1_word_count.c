//1). Take a string as an input, and count the number of words in the string. Take space, comma,exclamation, question mark and fullstop as delimitters for word counting.

#include<stdio.h>
int main()
{
	char s[100];
	scanf("%[^\n]s",s);
	int i,count=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==' '||s[i]==','||s[i]=='!'||s[i]=='?'||s[i]=='.')
			count++;
	}
	printf("no of words=%d\n",count);
	return 0;
}
