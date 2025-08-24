/*Repeat the eligibility program for n times. Read maths,physics and chemistry marks for n students, and print if each student is eligible for the course or not based on below conditions:
	1)Maths >= 60 
	2)Physics >=50 
	3)Chemistry >= 40
	4)Maths + Physics + Chemistry >= 200 
		or
	5)Maths + Physics >= 150 */
#include<stdio.h>
int main()
{
	int i=1,n;
	scanf("%d",&n);
	while(i<=n)
	{
		int math,phys,chem;
		scanf("%d%d%d",&math,&phys,&chem);
		if(math>=60 && phys>=50 && chem>=40 && ((math+phys+chem)>=200 || (math+phys)>=150))
			printf("student is eligible\n");
		else
			printf("not eligible\n");
		i++;
	}
	return 0;
}

