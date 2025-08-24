#include <stdio.h>
int main(int argc,char *argv[])
{
	int x,y,z;
	char *fp1.*fp2,*fp3;
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"a+");
	fp3=fopen("sort.txt","w+");
	if(fp1==NULL||fp2==NULL||fp3==NULL)
		printf("Files open fails\n");
	else
	{
		while(1)
		{
			x=getw(fp1);
			if(x==EOF)
				break;
			putw(x,fp2);
		}
		rewind(fp2);
	//	while(1)
		{
			
		}
		
	}
}	
