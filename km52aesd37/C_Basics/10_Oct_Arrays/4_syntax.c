/*4 Try experimenting with the below array syntaxes and see the results,check their sizes, try to also read values for elements and print them:</br>
1.int arr[5] = {};
2.int arr[10] = {2.4,5.6,7.3};
3.int arr[3] = {1,2,3,4,5};
4.int arr[0] = {};
5.int arr[0] = {1,2,3,4,5};
6.int arr[] = {};
7.int arr[‘a’];	*/
#include<stdio.h>
int main()
{
	int i;
	int arr1[5]={};
	printf("%d\n",sizeof(arr1));
	for(i=0;i<5;i++)
		printf("%d\t",arr1[i]);
	printf("\n");
/*				output: size:20
					0	0	0	0	0	*/
	int arr2[10]={2.4,5.6,7.3};
	printf("%lu\n",sizeof(arr2));
	for(i=0;i<10;i++)
		printf("%d\t",arr2[i]);
/*				output: size:40
					 2	5	7	0	0	0	0	0	0	0	*/
	int arr3[3]= {1,2,3,4,5};
	printf("%lu\n",sizeof(arr3));
	for(i=0;i<5;i++)
		printf("%d\t",arr3[i]);
/*			output: warning
				size:12
				 1	2	3	-628047616	-1555900645
				4_syntax.c: In function ‘main’:
				4_syntax.c:23:22: warning: excess elements in array initializer
				4_syntax.c:23:22: note: (near initialization for ‘arr3’)
				4_syntax.c:23:24: warning: excess elements in array initializer
				4_syntax.c:23:24: note: (near initialization for ‘arr3’)
	*/
	int arr4[0]={};
	printf("%d\n",arr4[0]);
	printf("%lu\n",sizeof(arr4));
/*							output: Garbage value	
								size:0		*/
	int arr5[0]={1,2,3,4,5};
	printf("%lu\n",sizeof(arr5));
	for(i=0;i<5;i++)
		printf("%d\t",arr5[i]);
/*				output: 0
					
					4_syntax.c: In function ‘main’:
					4_syntax.c:39:15: warning: excess elements in array initializer
					  int arr5[0]={1,2,3,4,5};
						               ^
					4_syntax.c:39:15: note: (near initialization for ‘arr5’)
					4_syntax.c:39:17: warning: excess elements in array initializer
					  int arr5[0]={1,2,3,4,5};
					4_syntax.c:39:17: note: (near initialization for ‘arr5’)
					4_syntax.c:39:19: warning: excess elements in array initializer
						  int arr5[0]={1,2,3,4,5};
	                   ^
					4_syntax.c:39:19: note: (near initialization for ‘arr5’)
					4_syntax.c:39:21: warning: excess elements in array initializer
		                  			   ^
					4_syntax.c:39:21: note: (near initialization for ‘arr5’)
					4_syntax.c:39:23: warning: excess elements in array initializer
	                       ^
					4_syntax.c:39:23: note: (near initialization for ‘arr5’)
	*/
	int arr6[]={};
	printf("%lu\n",sizeof(arr6));
/*			output:0	*/
	int arr7['a'];
		printf("%lu\n",sizeof(arr7));
//				output:388
}
