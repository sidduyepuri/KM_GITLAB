//1)Create a character pointer array, initialise the pointers to read only strings. Sort the array and print.
#include<stdio.h>
#include<string.h>
void sort(const char *ptr[]);
int main()
{
	const char *ptr[4]={"word","dog","ear","pen"};
	sort(ptr);
	return 0;
}

void sort(const char *ptr[])
{
	int i,j;
	int n=4;
	const char *temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(ptr[i],ptr[j])>0)
			{
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;	
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s\n",ptr[i]);
	}
}
