//6 declare different pointers with different data types. Print the sizes of the pointer variables using sizeof operator. Why do u think all of them are giving same size irrespective of the data type ?
#include<stdio.h>
int main()
{
	int *ptr1;
	float *ptr2;
	char *ptr3;
	double *ptr4;
	printf("sizeof int=%lu\n",sizeof(ptr1));
	printf("sizeof float=%lu\n",sizeof(ptr2));
	printf("sizeof char=%lu\n",sizeof(ptr3));
	printf("sizeof double=%lu\n",sizeof(ptr4));
	return 0;
}
//Reason: Irrespective of data type address is fixed for store address of a variable.size of the pointer is 8bytes.
