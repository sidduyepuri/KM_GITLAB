/*2 ) Extend the super market program, so that, whenever the user chooses to quit (super market closing),at that time it will print the below report and wait to read a character (getchar() statement). On enter, the program will close.
Report :
1 ) Current Stock :
2 ) Total sales made today :
3 ) Total number of times sale was done :
4 ) Total purchase made today :
5 ) Total number of times purchase was done :		*/
#include<stdio.h>
int sell();
int purchase();
extern int stock; 
extern int purchas,p,sales,s; 
int main()
{
	int n;
	do
	{
		printf("Enter your choice:\n 1) check Stock.\n 2) Sell.\n 3) Purchase. \n 4) quit.\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("Available stock=%d\n",stock); break;
			case 2: sell(); break;
			case 3: purchase(); break;
			case 4: break;

			default: printf("Enter correct choice: \n");
		}
		printf("Current stock:%d\n",stock);
		printf("Total sales made today:%d\n",sales);
		printf("Total number of times sale was done:%d\n",s);
		printf("Total purchase made today:%d\n",purchas);
		printf("Total number of times purchase was done:%d\n",p);
		if(n==4){
			char ch;
			printf("Do you want to close the supermarket:");
			scanf(" %c",&ch);
			if(ch=='s')
				break;
			else
				continue;
		}
	}while(1);
	return 0;

}
