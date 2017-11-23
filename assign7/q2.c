/***********************************************************
 
 Program to delete duplicate elements from an ordered link list
 
 Author: leonatwork(Noel Aby Das)
 
 **********************************************************/
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *link;
};
struct node *first=NULL;

void insert()
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  if(first!=NULL)
  {
    printf("\nNumber to insert should be less than %d\n",first->data);
  }
  printf("Enter data: ");
  scanf("%d",&(temp->data));
  if(first!=NULL&&temp->data>first->data)
  {
    printf("This record cannot be entered at the start\n");
    return;
  }
  temp->link=first;
  first=temp;
}
void duplidelete()
{
  struct node *temp=first,*prev=first,*save=first;
  while(temp!=NULL)
  {
    temp=temp->link;
    if(temp!=NULL)
    {
      if(prev->data==temp->data)
      {
        prev->link=temp->link;
      }
      else
        prev=temp;
    }
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
    temp=temp->link;
  }
}
int main()
{
  int c;
  while(1)
  {
  printf("\nMenu\n1. insert\n2. duplidelete\n3. display\n4. exit\nEnter your choice : ");
  scanf("%d",&c);
  switch(c)
  {
    case 1:
     insert();
     break;
    case 2:
     duplidelete();
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
