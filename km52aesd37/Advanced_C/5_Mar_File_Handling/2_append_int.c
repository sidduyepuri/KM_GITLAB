#include <stdio.h>
int main()
{
	int x=0;
	char ch;
	FILE *fp;
	fp=fopen("int.txt","a+");
	if(fp==NULL)
		printf("File is not exist\n");
	else
	{
		while(1)
		{
			scanf("%d",&x);
			if(x == -1)
				break;
			putw(x,fp);
		}
		rewind(fp);
		while(1)
		{
			x=getw(fp);
			if(x == EOF)
				break;
			printf("%d\n",x);
		}
		fclose(fp);
	}
	return 0;
}

