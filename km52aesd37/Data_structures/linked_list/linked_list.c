#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
	int id;
	char name[10];
	struct student *next;
}stu;

stu *last=NULL;

void *printlist(stu *H)
{
	while(H!=NULL)
	{
		printf("-------->>>>>>ID=%d NAME=%s\n",H->id,H->name);
		H=H->next;
	}
}

stu *createnode()
{
	stu *node;
	node=(stu *)malloc(sizeof(stu));
	printf("Enter id and name:");
	scanf("%d%s",&node->id,node->name);
	node->next=NULL;
	return node;
}

stu *createlist()
{
	stu *head=NULL,*new=NULL;
	char ch='y';
	while(ch=='y')
	{
		new=createnode();
		if(head==NULL)
			head=new;
		else
			last->next=new;
		last=new;	
		printf("Do you want to create one more node?(y/n)");
		scanf(" %c",&ch);
	}
	return head;
}

void searchelement(stu *H,int id)
{
	while(H!=NULL)
	{
		if(H->id==id)
		{
			printf("#####Id found######\n");
			return;
		}
		H=H->next;
	}
	printf("######Id not found#######\n");
}

int countlist(stu *H)
{
	int count=0;
	while(H!=NULL)
	{
		count++;
		H=H->next;
	}
	return count;
}

stu *insertatbeg(stu *H)
{
	stu *new=NULL;
	new=createnode();
	new->next=H;
	return new;
}

stu *insertatend(stu *H)
{
	stu *new=NULL;
	new=createnode();
	last->next=new;
	last=new;
	return H;
}

stu *insertinbtw(stu *H,int pos)
{
	stu *new=NULL,*T=H;
	int i;
	new=createnode();
	for(i=1;(T!=NULL)&&(i<pos-1);i++)
		T=T->next;
	if(pos==1)
	{
		new->next=T->next;
		H=new;
	}
	else
	{
		new->next=T->next;
		T->next=new;		
	}
	return H; 
}

stu *insertatvalbef(stu *H,int data)
{
	stu *T=H,*N=NULL;
	while(T->next!=NULL)
	{
		if(T->next->id==data)
		{
			N=createnode();
			N->next=T->next;
			T->next=N;
			break;
		}
		T=T->next;
	}
	return H;
}

stu *insertatvalaft(stu *H,int data)
{
	stu *T=H,*N=NULL;
	while(T->next!=NULL)
	{
		if(T->id==data)
		{
			N=createnode();
			N->next=T->next;
			T->next=N;
			break;
		}
		T=T->next;
	}
	return H;
}

stu *deletenode(stu *H,int data)
{
	stu *T=H,*temp;
	while(T!=NULL)
	{
		if(T->id==data)
		{
			temp=H;
			H=T->next;
			free(temp);
			break;
		}
		if(T->next->id==data)
		{
			temp=T->next;
			T->next=T->next->next;
			free(temp);
			break;
		}
		T=T->next;
	}
	return H;
}

stu *deleteatbefore(stu *H,int data)
{
	stu *T=H,*temp;
	while(T!=NULL)
	{
		if(T->id==data)
		{
			printf("This is first node, There no node before this data.\n");
			break;
		}
		if(H->next->id==data)
		{
			temp=H;
			H=T->next;
			free(temp);
			break;
		}
		else if(T->next->next->id==data)
		{
			temp=T->next;
			T->next=T->next->next;
			free(temp);
			break;
		}
		T=T->next;
	}
	return H;
}

stu *deleteatafter(stu *H,int data)
{
	stu *T=H,*temp;
	while(T->next!=NULL)
	{
		if(T->next->id==data)
		{
			temp=T->next;
			T->next=T->next->next;
			free(temp);
			break;
		}
		T=T->next;
	}
	return H;


}

stu *deleteatposition(stu *H,int pos)
{
	stu *T=H,*temp;
	int i=1;
	for(;T!=NULL&&i<pos-1;i++)
		T=T->next;
	if(T==NULL)
	{
		printf("position is exceeded\n");
	}
	while(T!=NULL)
	{
		if(pos==1)
		{
			temp=H;
			H=T->next;
			free(temp);
			break;
		}
		else
		{
			temp=T->next;
			T->next=T->next->next;
			free(temp);
			break;
		}
		T=T->next;
	}
	return H;

}

stu *Reverselist(stu *head)
{
	stu *T,*prev,*next_node;
	prev=NULL;
	T=head;
	while(T!=NULL)
	{
		next_node=T->next;
		T->next=prev;
		prev=T;
		T=next_node;
	}
	head=prev;
	return head;
}

int main()
{
	int id,pos,choice,count,data;
	char name[10];
	stu *Head=NULL;
	while(1)
	{
		printf("1.create List\n");
		printf("2.Display List\n");
		printf("3.count List\n");
		printf("4.search List\n");
		printf("5.insert on empty List/insert at beg\n");
		printf("6.insert at end\n");
		printf("7.insert after value\n");
		printf("8.insert before value\n");
		printf("9.insert at position\n");
		printf("10.delete node\n");
		printf("11.Reverse list\n");
		printf("12.Quit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	Head=createlist();
				break;
			case 2: printlist(Head);
				break;
			case 3: count=countlist(Head);
				printf("No of nodes in list is=%d\n",count);
				break;
			case 4:	printf("Enter Id of the student for search:");
				scanf("%d",&id);
				searchelement(Head,id);
				break;
			case 5:	Head=insertatbeg(Head);
				break;
			case 6:	Head=insertatend(Head);
				break;
			case 7:	printf("Enter value for add node before value:");
				scanf("%d",&data);
				Head=insertatvalaft(Head,data);
				break;
			case 8:	printf("Enter value for add node before value:");
				scanf("%d",&data);
				Head=insertatvalbef(Head,data);
				break;
			case 9:	printf("Enter position to insert\n");
				scanf("%d",&pos);
				Head=insertinbtw(Head,pos);
				break;
			case 10:printf("1.delete data node.\n"); 
				printf("2.delete before data.\n"); 
				printf("3.delete after data.\n"); 
				printf("4.delete at position.\n"); 
				printf("Again choose delete option:");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1: printf("Enter data for delete that node:\n");
						scanf("%d",&data);
						Head=deletenode(Head,data);
						break;
					case 2: printf("Enter data for before node delete.\n");	
						scanf("%d",&data);
						Head=deleteatbefore(Head,data);
						break;
					case 3: printf("Enter data for before after delete.\n");	
						scanf("%d",&data);
						Head=deleteatafter(Head,data);
						break;
					case 4: printf("Enter data for before node delete.\n");	
						scanf("%d",&pos);
						Head=deleteatposition(Head,pos);
						break;
					default: printf("Wrong delete option");
				}
				break;
			case 11: printf("Reversing Entire list\n");
				 Head=Reverselist(Head);
				 break;
			case 12: exit(1);
			default: printf("Wrong choice\n");
		}
	}
}

