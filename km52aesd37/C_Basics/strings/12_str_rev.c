/*12) void strrev( char str[]);
  reverse the string (without using any extra array)
	eg., input : str[] = "Kernel";
	output : str[] = "lenreK"	*/
#include<stdio.h>
#include<string.h>
void str_rev( char str[]);
int main()
{
	char str[20];
	scanf("%s",str);
	str_rev(str);
	printf("%s\n",str);
	return 0;	
}
void str_rev(char str[])
{
	int i,j=strlen(str)-1,temp;
	for(i=0;i<j;i++,j--){
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}

}
