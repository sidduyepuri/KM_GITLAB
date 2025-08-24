/*9) implement a function to receive a sentence as input, and return the string with the words reversed,
eg., input: Kernel Masters is best for embedded systems.
output: systems embedded for best is Masters Kernel.	*/
#include<stdio.h>
#include<string.h>
void str_reverse(char temp[]);
int main()
{
	char str[100];
	scanf("%[^\n]s",str);
	char rev[100]="",temp[100];
	int i,j,len;
	len=strlen(str);
	for(i=len-1;i>=0;i--){
		for(j=0;i>=0&&str[i]!=' ';j++,i--)
			temp[j]=str[i];
		temp[j]='\0';
		str_reverse(temp);
		strcat(rev,temp);
		strcat(rev," ");
	}
	printf("%s\n",rev);
}
void str_reverse(char temp[])
{
	int i;
	char t;
	int j=strlen(temp)-1;
	for(i=0;i<j;i++,j--)
	{
		t=temp[i];
		temp[i]=temp[j];
		temp[j]=t;
	}
}


