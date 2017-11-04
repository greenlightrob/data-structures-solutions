#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *lptr,*rptr;
};
struct node *first=NULL;
void insert()
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data to be inserted :");
	scanf("%d",&(temp->data));
	temp->lptr=NULL;
	temp->rptr=first;
	first=temp;
}
void reverse()
{
	struct node *temp = first;
	if(temp==NULL)
		return;
	else if(temp->rptr==NULL)
		return;
	while(temp!=NULL)
	{
		struct node *t=temp->rptr,*s=temp->lptr,*p=temp;
		temp->rptr=temp->lptr;
		temp->lptr=t;
		first=temp;
		temp=temp->lptr;
		if(temp!=NULL)
			temp->lptr=p;
	}
}
void display()
{
	struct node *temp=first;
	if(temp==NULL)
	{
		printf("\nEmpty list");
		return;
	} 
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->rptr;
	}
}
int main()
{
	int c;
	while(1)
	{
	printf("\nMenu\n1. insert\n2. reverse\n3. display\n4. exit\nEnter your choice : ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
		 insert();
		 break;
		case 2:
		 reverse();
		 break;
		case 3:
		 display();
		 break;
		case 4:
		 exit(1); 
	}
	}
	return 0;
}