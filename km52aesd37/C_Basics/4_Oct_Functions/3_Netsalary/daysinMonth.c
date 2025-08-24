
int Isleapyear(int );

int NoofDaysinMonth(int m,int y)
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		return 31;
	else if(m==2){
		if(Isleapyear(y)==1)
			return 29;
		else
			return 28;
	}
	else if(m==4||m==6||m==9||m==11)
		return 30;
	return 0;
}
int Isleapyear(int y)
{
	if((y%100!=0&&y%4==0)||(y%400==0))
		return 1;
	else
		return 0;
}
