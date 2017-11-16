/***********************************************************
 
     Doubly linked linear list
 
 Author: leonatwork(Noel Aby Das)
 
 **********************************************************/

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int roll;
  char name[25];
  float cg;
  struct node *lptr;
  struct node *rptr;
};
struct node *first=NULL;
void insertbeg()
{
  struct node *save=first,*temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter roll no : ");
  scanf("%d",&temp->roll);
    if(save!=NULL)
  {
    while(save!=NULL)
    {
      if(save->roll==temp->roll)
      {
        printf("\nRoll no. already exists\n");
        return;
      }
      save=save->rptr;
    }
  }
  printf("Enter name : ");
  scanf("%s",temp->name);
  printf("Enter cgpa : ");
  scanf("%f",&temp->cg);
  temp->lptr=NULL;
  temp->rptr=first;
  first=temp;
}
void insertend()
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *save=first;
  if(first==NULL)
  {
   insertbeg();
   return;
  }
  printf("Enter roll no : ");
  scanf("%d",&temp->roll);
    if(save!=NULL)
  {
    while(save!=NULL)
    {
      if(save->roll==temp->roll)
      {
        printf("\nRoll no. already exists\n");
        return;
      }
      save=save->rptr;
    }
  }save=first;
  printf("Enter name : ");
  scanf("%s",temp->name);
  printf("Enter cgpa : ");
  scanf("%f",&temp->cg);
  while(save->rptr!=NULL)
  {
    save=save->rptr;
  }   
  temp->lptr=save;
  save->rptr=temp;
  temp->rptr=NULL;
}
void insertbet()
{
 int pos,k=0;
 printf("Enter the position you want to enter : ");
 scanf("%d",&pos);
 if(pos==1)
 {
   insertbeg();
   return;
 }
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 struct node *save=first,*next;
 while(save!=NULL)
 {
  k++;
  save=save->rptr;
 }
 if(k+1==pos)
 {
   insertend();
   return;
 }
 if(k<pos||pos<=0)
 {
  printf("\nInvalid position\n");
  return;
 }
 
 save=first;
 while(pos>1)
 {
  save=save->rptr;
  pos--;
 }
  printf("Enter roll no : ");
  scanf("%d",&temp->roll);
    if(next!=NULL)
  {
    while(next!=NULL)
    {
      if(next->roll==temp->roll)
      {
        printf("\nRoll no. already exists\n");
        return;
      }
      next=next->rptr;
    }
  }
  printf("Enter name : ");
  scanf("%s",temp->name);
  printf("Enter cgpa : ");
  scanf("%f",&temp->cg);
  struct node *prev=(struct node*)malloc(sizeof(struct node));
  prev=save->lptr;
  prev->rptr=temp;
  temp->lptr=prev;
  temp->rptr=save;
  save->lptr=temp;
}
void deletebeg()
{
 struct node *temp=first;
 if(first==NULL)
  {
    printf("Empty list");
    return;
  }
 temp=temp->rptr;
 first=temp;
 if(first==NULL)
  return;
 else
  first->lptr=NULL;
}
void deletend()
{
 int len=0;
 if(first==NULL)
 {
     printf("\nEmpty list\n");
     return;
 }
struct node *save=first,*prev=first;
  while(save!=NULL)
  {
	len++;
    save=save->rptr;
  }save=first;
 if(len==1)
  {
   deletebeg();
   return;
  }
 	while(len>1)
    {
      len--;
      prev=save;
      save=save->rptr;
    }
    prev->rptr=save->rptr;
}
void deletebet()
{
  int pos,len=0;
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *save=first,*prev=first;
  while(save!=NULL)
  {
	len++;
    save=save->rptr;
  }
  if(len==0)
  {
   printf("\nEmpty list\n");
   return;
  }
  printf("Enter the position : ");
  scanf("%d",&pos);
  if(len<pos||pos<=0)
   {
	 printf("\nInvalid position\n");
	 return;
   }
  else if(pos==1)
   {
     deletebeg();
     return;
   }
  else
   {
    save=first;
 	while(pos>1)
    {
      pos--;
      prev=save;
      save=save->rptr;
    }
    prev->rptr=save->rptr;
   }
  
}


void searchroll()
{
  int r;
  printf("Enter the roll number to be searched : ");
  scanf("%d",&r);
  struct node *temp=first;
  if(first==NULL)
  {
    printf("empty list\n");
    return;
  }
  while(temp!=NULL)
  {
	if(temp->roll==r)
     {
        printf("\nName : %s\tcgpa : %f\n",temp->name,temp->cg);
        return;
     }
    temp=temp->rptr;
  }
  printf("\nRecord doesnt exist\n");
}
void searchname()
{
 char str[25];
 int i,f=0,flag=0;
 printf("Enter the name to be seached : ");
 scanf("%s",str);
 struct node *temp=first;
 if(first==NULL)
 {
  printf("\nEmpty list\n");
  return;
 }
 while(temp!=NULL)
 {
  f=0;
  for(i=0;str[i]!='\0'&&temp->name[i]!='\0';i++)
  {
    if(str[i]!=temp->name[i])
     {
       f=1;
       break;
     }
  }
  if(f==0&&str[i]=='\0'&&temp->name[i]=='\0')
   {
     printf("\nRoll no: %d\tCGPA: %f\n",temp->roll,temp->cg);
     flag=1;
   }
  temp=temp->rptr;
 }
 if(flag==0)
   printf("\nRecord not found\n");
}
void searchcgpa()
{
  float c;
  int flag=0;
  printf("Enter the cgpa number to be searched : ");
  scanf("%f",&c);
  struct node *temp=first;
  if(first==NULL)
  {
    printf("empty list\n");
    return;
  }
  while(temp!=NULL)
  {
	if(temp->cg==c)
     {
        printf("\nName : %s\tRoll no : %d\n",temp->name,temp->roll);
        flag=1;
     }
    temp=temp->rptr;
  }
  if(flag==0)
  printf("\nRecord doesnt exist\n");
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
  printf("\nRoll no : %d\t",temp->roll);
  printf("Name : %s\t",temp->name);
  printf("Enter cgpa : %f\n",temp->cg);
  temp=temp->rptr;
  }
}
void main()
{
int n;
printf("enter choice\n1.insertbeg\n2.insertend\n3.insertbet\n4.deletebeg\n5.deletend\n6.deletebet\n7.searchroll\n8.searchname\n9.searchcgpa\n10.display\n11.exit");
while(1)
{
printf("\nenter choice : ");
scanf("%d",&n);
printf("\n");
switch(n)
{
 case 1:
  insertbeg();
  break;
 case 2:
  insertend();
  break;
 case 3:
  insertbet();
  break;
 case 4:
  deletebeg();
  break;
 case 5:
  deletend();
  break;
 case 6:
  deletebet();
  break;
 case 7:
  searchroll();
  break;
 case 8:
  searchname();
  break;
 case 9:
  searchcgpa();
  break;
 case 10:
  display();
  break;
 case 11:
  exit(1);
}

}}
