#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};
struct node *first=NULL,*head=NULL;
void insert()
{
	  struct node *next=first,*q,*temp=(struct node*)malloc(sizeof(struct node));
	  printf("Enter the data to be inserted : ");
	  scanf("%d",&(temp->data));
	  temp->link=first;
	  q=first;
	  first=temp;
	  struct node *save=first;
	  if(first->link==NULL)
	  {
	   first->link=first;
		}
	  else if(first->link!=NULL)
	   {
			do{
				save=save->link;
				}while(save->link!=q);
		save->link=first;
	   }

}
void split()
{
	struct node *temp = first,*save = first,*q=first;
	head=NULL;
	if(temp==NULL)
		return;
	else if(temp->link==temp)
		return;
	struct node *t;
	do{
		t=temp;
		temp=temp->link;
		save=(save->link)->link;
		if(save->link==q)
			{
				t=temp;
				break;
			}
		else if(save==q)
			break;
	}while(1);

	head=t->link;
	t->link=first;

	save=head;
	struct node *prev,*save1=head;
	do{
		prev=save1;
		save1=save1->link;
		  if(save1==first)
		  	{
		  		prev->link=head;
		  		break;
		  	}
		  else if(save1->link==first)
		  {
		  	save1->link=head;
		  	break;
		  }
		}while(1);
		
}
void display()
{
	struct node *temp1=first,*temp2=head,*q;
	if(temp1==NULL&&temp2==NULL)
	{
		printf("\nEmpty lists");
		return;
	} 
	else if(temp1==NULL&&temp2!=NULL)
	{
		printf("\nFirst list empty");
		printf("\nSecond list : ");
		q=temp2;
		  do
		  {
		      printf("%d -> ",temp2->data);
		    temp2=temp2->link; 
		  }while(temp2!=q);
		return;
	}
	else if(temp2==NULL&&temp1!=NULL)
	{
		printf("\nFirst list : ");
		q=temp1;
		  do
		  {
		      printf("%d -> ",temp1->data);
		    temp1=temp1->link; 
		  }while(temp1!=q);
		printf("\nSecond list empty ");
		return;
	}
		printf("\nFirst list : ");
		q=temp1;
		  do
		  {
		      printf("%d -> ",temp1->data);
		    temp1=temp1->link; 
		  }while(temp1!=q);
		printf("\nSecond list : ");
		q=temp2;
		  do
		  {
		      printf("%d -> ",temp2->data);
		    temp2=temp2->link; 
		  }while(temp2!=q);

}
int main()
{
	int c;
	while(1)
	{
	printf("\nMenu\n1. insert\n2. split\n3. display\n4. exit\nEnter your choice : ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
		 insert();
		 break;
		case 2:
		 split();
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