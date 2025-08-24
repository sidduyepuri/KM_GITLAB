//11 Write a function to return the average of marks of all students in a class.
#include<stdio.h>
float average(int arr[],int,int);
int main()
{
	int n,m,i;
	float avg;
	printf("Enter number of students:");
	scanf("%d",&n);
	printf("Enter number of subjects:");
	scanf("%d",&m);
	int arr[m];
	avg=average(arr,n,m);
	printf("Average=%.2f\n",avg);
	return 0;
}
float average(int arr[],int n,int m)
{	
	int i,j;
	float sum=0,temp;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&arr[j]);
			sum+=arr[j];
		}
		sum=sum/m;
		temp+=sum;
		sum=0;
	}
	temp=(float)temp/n;
	return temp;

}
