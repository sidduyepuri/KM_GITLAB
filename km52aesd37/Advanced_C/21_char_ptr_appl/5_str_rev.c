/*5) Implement your own string reverse function using the above swap function to swap the edges while reversing.
	try calling the string reverse function using
	1) string variable
	2) string constant

	note down the output and analyze the reasons.	*/
#include<stdio.h>
#include<string.h>
char * strrevc(const char *);
char * strrev(char *);
int main()
{
//	char *str="kernel";
	char str[20];
	char *str2;
	scanf("%s",str);
	str2=strrev(str);
	//str2=strrevc(str);
	printf("%s\n",str2);
	return 0;	
}
//1) string variable
char *strrev(char *str)
{
	int i,j=strlen(str)-1,temp;
	for(i=0;i<j;i++,j--){
		temp=*(str+i);
		*(str+i)=*(str+j);
		*(str+j)=temp;
	}
	return str;
}
//2) string constant
/*char *strrevc(const char *str)
{
	int i,j=strlen(str)-1,temp;
	for(i=0;i<j;i++,j--){
		temp=*(str+i);
		*(str+i)=*(str+j);
		*(str+j)=temp;
	}
	return str;
}*/
/*5_str_rev.c: In function ‘strrevc’:
5_str_rev.c:37:11: error: assignment of read-only location ‘*(str + (sizetype)i)’
   *(str+i)=*(str+j);
           ^
5_str_rev.c:38:11: error: assignment of read-only location ‘*(str + (sizetype)j)’
   *(str+j)=temp;
           ^
5_str_rev.c:40:9: warning: return discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
  return str;
         ^~~
*/
