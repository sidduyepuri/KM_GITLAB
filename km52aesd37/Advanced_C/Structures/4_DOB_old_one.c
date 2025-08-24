/*4) write a function to take the array of structures as arguments and return the structure element with the oldest date of birth.
    return the structure variable using return statement and array element with index. Return type of the function will be struct student.

	eg.,
	struct student oldest student(struct student arr[])
	{ 
		return arr[i]; // find the index at which date of  birth is oldest using date comparison function
	}		*/
#include "struct.h"
struct student oldest(struct student arr[],int n);
int date_compare(struct student arr[],int n);
int main()
{
	int n,i,j,sum=0;
	struct student res;
	float percent;
	char *nm;
	printf("Enter no of. students:");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
		printf("Enter student%d ID:",i+1);
		scanf("%d",&s[i].ID);
		printf("Enter student%d name:",i+1);
		scanf("%s",s[i].name);
		printf("Enter student%d DOB:",i+1);
		scanf("%d-%d-%d",&s[i].d,&s[i].m,&s[i].y);
		printf("Enter student%d gender:",i+1);
		scanf(" %c",&s[i].gender);
	}
	res=oldest(s,n);
	printf("oldest:%d-%d-%d \n",res.d,res.m,res.y);
}
struct student oldest(struct student arr[],int n)
{
	int i;
	i=date_compare(arr,n);	
	return arr[i]; // find the index at which date of  birth is oldest using date comparison function
}
int date_compare(struct student arr[],int n)
{
	int i,j;
	for(i=0,j=0;i<n;i++)
	{
		if(i>0)
		{
			if(arr[i].y>arr[j].y)
				j=i-1;
			else if(arr[i].y<arr[j].y)
				j=i;
			else if(arr[i].m>arr[j].m)
				j=i-1;
			else if(arr[i].m<arr[j].m)
				j=i;
			else if(arr[i].d>arr[j].d)
				j=i-1;
			else if(arr[i].d<arr[j].d)
				j=i;
		}
	}
	return j;
}
