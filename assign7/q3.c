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
  struct node *save=first,*temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter data : ");
  scanf("%d",&(temp->data));
  temp->link=first;
  first=temp;
}
void swap()
{
  if(first==NULL)
    return;
  else if(first->link==NULL)
    return;
  struct node *temp=first,*next=first->link,*prev=NULL;
  while(next!=NULL)
  {
    temp->link=next->link;
    next->link=temp;
    if(prev!=NULL)
    {
      prev->link=next;
    }
    else
      first=next;
    prev=temp;
    temp=temp->link;
    if(temp!=NULL)
      next=temp->link;
    else
      break;
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
  printf("\nMenu\n1. insert\n2. swap\n3. display\n4. exit\nEnter your choice : ");
  scanf("%d",&c);
  switch(c)
  {
    case 1:
     insert();
     break;
    case 2:
     swap();
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