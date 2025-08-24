/*4) read an integer and print it back in complete number name expansion with place values as below:

eg., 458
output : four hundred fifty eight

eg., 1458
output: one thousand four hundred fifty eight	*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int count=0,i=0,res,l,n;
	scanf("%d",&n);
	char str[10];
	char *num[]={"\0","one","two","three","four","five","six","seven","eight","nine"};
	char *tens[]={"\0","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
	char *thousand[]={"\0","\0","hundred","thousand","lakhs"};
	char *teen[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	i=n;
	while(i>0)
	{
		i/=10;
		count++;
	}
	if(count>=0&&count<=7)
	{
		res=n/1000;
		if(res<10&&res>0)
			printf("%s %s ",num[res],thousand[3]);
		if(res>=11&&res<=19)
			printf("%s %s ",teen[res%10],thousand[3]);
		if(res>=20||res==10)
			printf("%s %s %s ",tens[res/10],num[res%10],thousand[3]);
		res=(n%1000)/100;
		if(res)
			printf("%s %s ",num[res],thousand[2]);
		res=(n%100)/10;
		if(res!=1)
			printf("%s %s ",tens[res],num[n%10]);
		if(res==1)
			printf("%s ",teen[n%10]);
		printf("\n");
	}
}
