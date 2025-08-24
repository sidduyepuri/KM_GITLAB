/*3) WAP - for the 4 departments of a supermarket : Sales, Purchase, Stock and SuperMarket in four different source code files.
Stock : Maintains a variable for available stock.
Sales : Has one function: Sell – It will reduce the stock by the number of items sold. Before selling, check if enough stock is available.
Purchase : Has one function : Purchase – will increase the stock by the number of items purchased.Set a max value for stock, before purchasing check if the stock room has enough space for new items or not.
SuperMarket : Display menu with choices : 1 ) check AvailableStock 2 ) Purchase new items 3) Sell items … this should be continuous as long as the user wants to continue. Program should stop when the user wants to quit.	*/
#include<stdio.h>
int purchase();
int sell();
extern int stock;
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
			case 4:break;

			default: printf("Enter correct choice: \n");
		}
	}while(n!=4);
	return 0;
}
