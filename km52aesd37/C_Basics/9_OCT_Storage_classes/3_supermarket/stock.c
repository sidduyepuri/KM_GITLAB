extern int items;
int stock=1000;
int deletestock(int);
int addstock(int items)
{
	stock+=items;
}
int deletestock(int items)
{
	stock-=items;
}

