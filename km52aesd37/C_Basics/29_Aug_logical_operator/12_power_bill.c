/*Find the power bill for the input number of units :
	0 - 200 units : 100/- min
	201 - 400 units : 100 + 0.65 per unit excess of 200
	401 - 600 units : 230 + 0.80 per unit excess of 400
	601 and above units : 390 + 1.00 per unit excess of 600*/
#include<stdio.h>
int main()
{
	int units;
	float bill;
	scanf("%d",&units);
	if(units<=200 && units>0)
		bill=100;
	else if(units<=400 && units>200)
		bill=100+0.65*(units-200);
	else if(units<=600 && units>400)
		bill=230+0.80*(units-400);
	else
		bill=390+1.00*(units-600);
	printf("%f\n",bill);
}
