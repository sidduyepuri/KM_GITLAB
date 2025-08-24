//Write a program that compares two files and returns 0 if they are equal and 1 if they are not equal.
#include <stdio.h>
int compare_files(FILE *fp1,FILE *fp2);
int main(int argc,char *argv[])
{
	int x=0;
	char ch;
	FILE *fp1,*fp2,*fp3;
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"r");
	if(fp1==NULL||fp2==NULL)
		printf("File is not exist\n");
	else
	{
		x=compare_files(fp1,fp2);
		if(x==0)
			printf("Both Files same\n");
		else
			printf("Files not a same\n");
	}
	return 0;
}

int compare_files(FILE *fp1,FILE *fp2)
{
	char ch1,ch2;
	while(1)
	{
		ch1=fgetc(fp1);
		ch2=fgetc(fp2);
		if(ch1!=ch2)
			return -1;
		if(ch1==EOF&&ch2==EOF)
			break;
	}
	return 0;
}

