//Read a set of numbers (number of inputs is input) and print if each given number is smaller or bigger than the previous number. For first number there will not be any output as there is no previous number.
#include<stdio.h>
int main()
{
	int i=1,n,temp;
	scanf("%d",&n);
	scanf("%d",&temp);
	while(i<=n)
	{
		int num;
		scanf("%d",&num);
		if(num>temp){
			temp=num;
			printf("%d is Bigger\n",temp);
		}
		else{
			temp=num;
			printf("%d is small\n",temp);
		}
	i++;
	}
	return 0;
}
