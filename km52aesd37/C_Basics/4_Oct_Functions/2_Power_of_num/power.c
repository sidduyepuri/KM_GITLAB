#include"main2.h"
int power(int m,int n,int temp)
{
	temp=m;
	int p=0;
	for(int i=1;i<n;i++){
		p+=multiply(m,n,temp);
		temp=p;
		p=0;
	}
	return temp;
}
