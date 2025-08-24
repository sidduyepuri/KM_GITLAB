/*1 ) WAP - with a function that prints the following message every nth time it is called : Hello! I am called nth time. Print the appropria    te subscript after the n, depending on the last digit.
 Output : The function should print the following ,
 I am called 1st time.
 I am called 2nd time.``
 I am called 3rd time…etc.
 The subscripts also should be printed appropriately. (st, nd ,rd and th etc.).
 Hint : numbers ending with 1 will have st as subscript.
 Numbers ending with 2 will have nd as subscript.
 Similarly, numbers ending with 3 will have rd and all the remaining numbers will have th.       */
#include<stdio.h>
void fun();
int i;
int main()
{
        int n;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
                fun();
        }
        return 0;
}

