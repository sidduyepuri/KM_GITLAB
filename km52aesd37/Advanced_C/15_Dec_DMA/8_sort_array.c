/*8)  Write a function that takes two sorted integer arrays as input, and returns an array of integers from both arrays in sorted order, excluding duplicate numbers. 
Assume that the input arrays are sorted.
eg., array1 : 10,12,13,14,15,16
array2 : 9,12,15,19,20
output array3 : 9,10,12,13,14,15,16,19,20		*/

#include<stdio.h>
#include<stdlib.h>
int *sorted_arr(int *,int *);
int n,m,k;
int main()
{
	int i;
	printf("enter arr1 size:");
	scanf("%d",&n);
	printf("enter arr2 size:");
	scanf("%d",&m);
	int *arr1=(int *)malloc(n*sizeof(int));
	int *arr2=(int *)malloc(m*sizeof(int));
	int *arr3=(int *)malloc((m+n)*sizeof(int));
	printf("array1:");
	for(i=0;i<n;i++)
	{
		scanf("%d",arr1+i);
	}
	printf("array2:");
	for(i=0;i<m;i++)
	{
		scanf("%d",arr2+i);
	}
	arr3=sorted_arr(arr1,arr2);
	printf("array3:");
	for(i=0;i<m+n;i++)
		printf("%d ",*(arr3+i));
	printf("\n");
}
int * sorted_arr(int *arr1,int *arr2)
{
	int i,j;
	int *arr3=(int *)malloc((m+n)*sizeof(int));
	for(i=0;i<(m+n);i++)
	{
		if(i<n)
			arr3[i]=arr1[i];
		else{
			arr3[i]=arr2[j];
			j++;
		}
	}
	int l=m+n,temp;
	for(i=0;i<l;i++){
		for(j = i+1; j < l; j++){
			if(arr3[i] == arr3[j])
			{
				n--;
				for(k = j; k <l; k++)
				{
					arr3[k] = arr3[k+1];
				}
				j--;
				l--;
			}
			if(arr3[i]>arr3[j])
			{
				temp=arr3[i];
				arr3[i]=arr3[j];
				arr3[j]=temp;
			}
		}
	}
	return arr3;
}
