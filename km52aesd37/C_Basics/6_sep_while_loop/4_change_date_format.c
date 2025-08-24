/* Read n number of dates, and print  the date back in below format:

	eg., if one of the dates given is 3-4-2000, output should be 
	3 April 2000.*/
#include<stdio.h>
int main()
{
	int i=1,n;
	scanf("%d",&n);
	while(i<=n)
	{
		int d,m,y;
		scanf("%d-%d-%d",&d,&m,&y);
		switch(m)
		{
			case 1: printf("%d-Jan-%d\n",d,y);
				break;
			case 2: printf("%d-Feb-%d\n",d,y);
				break;
			case 3: printf("%d-Mar-%d\n",d,y);
				break;
			case 4: printf("%d-Apr-%d\n",d,y);
				break;
			case 5: printf("%d-May-%d\n",d,y);
				break;
			case 6: printf("%d-Jun-%d\n",d,y);
				break;
			case 7: printf("%d-Jul-%d\n",d,y);
				break;
			case 8: printf("%d-Aug-%d\n",d,y);
				break;
			case 9: printf("%d-Sep-%d\n",d,y);
				break;
			case 10: printf("%d-Oct-%d\n",d,y);
				break;
			case 11: printf("%d-Nov-%d\n",d,y);
				break;
			case 12: printf("%d-Dec-%d\n",d,y);
		}
		i++;
	}
	return 0;
}
