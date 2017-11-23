/***********************************************************
 
 Program to implement functionalitites of a web browser
 like forward and backward using deque
 
 Author: leonatwork(Noel Aby Das)
 
 **********************************************************/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  char url[25];
  struct node *lptr;
  struct node *rptr;
};
struct node *first=NULL,*Current=NULL;
void open()
{
  struct node *save=first,*temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter url : ");
  scanf("%s",temp->url);
  temp->lptr=NULL;
  temp->rptr=Current;
  if(Current!=NULL)
  {
    if(Current->lptr!=NULL)
    {
      first=temp;
      Current->lptr=temp;
    }
  }
  Current=temp;
  first=temp;
  printf("Current url : %s\n",Current->url );
}


void back()
{
  if(Current==NULL)
  {
    printf("No previous site\n");
    return;
  }
  else if(Current->rptr==NULL)
  {
    printf("Home page\n");
    return;
  }
  else
  {
    Current=Current->rptr;
    printf("Current page url : %s\n",Current->url);
    return;
  }
}

void forward()
{
  if(!(Current==NULL||Current->lptr==NULL))
  {
    printf("No next site\n");
    return;
  }
  else
  {
    Current=Current->lptr;
    printf("Current page url : %s\n",Current->url);
    return;
  }
}
void display()
{
  struct node *temp=first;
  if(first==NULL)
  {
   printf("Empty list");
   return;
  }
  while(temp!=NULL)
  {
  printf("url : %s\t",temp->url);
  temp=temp->rptr;
  }
}
int main()
{
int n;
printf("Browswer\n");
printf("enter choice\n1.open link\n2.forward\n3.back\n4.exit");
while(1)
{
printf("\nenter choice : ");
scanf("%d",&n);
printf("\n");
switch(n)
{
 case 1:
  open();
  break;
 case 2:
  forward();
  break;
 case 3:
  back();
  break;
case 4:
  exit(1);
}

}
return 0;
}
