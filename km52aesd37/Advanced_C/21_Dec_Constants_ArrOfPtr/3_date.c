/*3)  read a date in d-m-y format and print it back in given format below:

eg input :2-3-2000
output: 2nd March, 2000

eg input: 4-1-2001
output: 4th January, 2001		*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int d,m,y;
	scanf("%d-%d-%d",&d,&m,&y);
	char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	char *subscript[]={"st","nd","rd","th"};
	if((d<=31&&d>=1)&&(m<=12&&m>=1))
	{
		if(d==1||d==21||d==31)
			printf("%d%s %s, %d\n",d,subscript[0],month[m-1],y);
		else if(d==2||d==22)
			printf("%d%s %s, %d\n",d,subscript[1],month[m-1],y);
		else if(d==3||d==23)
			printf("%d%s %s, %d\n",d,subscript[2],month[m-1],y);
		else
			printf("%d%s %s, %d\n",d,subscript[3],month[m-1],y);
	}
	else
		printf("Enter month and date correctly\n");

}
