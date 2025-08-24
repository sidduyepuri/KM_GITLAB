int Isleapyear(int);
int IsValidDate(int d1,int m1,int y1)
{
	if((m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)&&(d1<=31&&d1>=1))
		return 1;
	else if(m1==2){
		if((Isleapyear(y1)==1)&&(d1<=29&&d1>=1))
			return 1;
		else if(d1<=28&&d1>=1)
			return 1;
	}
	else if((m1==4||m1==6||m1==9||m1==11)&&(d1<=30&&d1>=1))
		return 1;
	return 0;
}
int Isleapyear(int y1)
{
	if(y1%100!=0&&y1%4==0||y1%400==0)
		return 1;
	else 
		return 0;
}
