#include"daysinMonth.h"
int CalculateNetSalary(int tot_sal,int lop,int m,int y)
{
	int total,per_day,deduct;
	per_day=tot_sal/NoofDaysinMonth(m,y);
	deduct=per_day*lop;
	total=tot_sal-deduct;
	return total;
}
