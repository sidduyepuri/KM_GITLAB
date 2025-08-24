/* void strcat( char d[] , char s[]);
	concatenates the content from source string to the end of destination string ( copy paste characters from s to  d , from null character index in d )
	eg., char d[] = "Kernel";
	char s[] = "Masters";			*/
#include<stdio.h>
#include<string.h>
void str_cat(char str1[],char str2[]);
int main()
{
	char str1[50],str2[20];
	scanf("%s%s",str1,str2);
	str_cat(str1,str2);
	printf("String1=%s\n",str1);
	return 0;
}
void str_cat(char str1[],char str2[])
{
	int i=strlen(str1),j;
	printf("%d\n",i);
	for(j=0;str2[j]!='\0';i++,j++){
		str1[i]=str2[j];
	}
	str1[i]='\0';
}
