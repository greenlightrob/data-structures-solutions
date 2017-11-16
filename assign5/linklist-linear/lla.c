/***********************************************************
 
     Linked list - linear
 
 Author: leonatwork(Noel Aby Das)
 
 **********************************************************/
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int roll;
 char name[25];
 float cg;
 struct node *link;
};
struct node *first=NULL;
void insertbeg()
{
  struct node *save=first,*temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter roll no : ");
  scanf("%d",&(temp->roll));
    if(save!=NULL)
  {
    while(save!=NULL)
    {
      if(save->roll==temp->roll)
      {
        printf("\nRoll no. already exists\n");
        return;
      }
      save=save->link;
    }
  }
  printf("Enter Name : ");
  scanf("%s",temp->name);
  printf("enter cgpa : ");
  scanf("%f",&(temp->cg));
  temp->link=first;
  first=temp;
}
void insertend()
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *save=first;
  printf("Enter roll no : ");
  scanf("%d",&(temp->roll));
    if(save!=NULL)
  {
    while(save!=NULL)
    {
      if(save->roll==temp->roll)
      {
        printf("\nRoll no. already exists\n");
        return;
      }
      save=save->link;
    }
  } save=first;
  printf("Enter Name : ");
  scanf("%s",temp->name);
  printf("enter cgpa : ");
  scanf("%f",&(temp->cg));
  temp->link=NULL;
  if(save!=NULL)
  {
  while(save->link!=NULL)
  {
    save=save->link;
  }
  save->link=temp;
  }
  else first=temp;
}
void insertbet()
{
  int pos;
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *save=first,*prev=first,*next=first;
  printf("Enter the position : ");
  scanf("%d",&pos);
  while(save!=NULL&&pos>1)
  {
	pos--;
    prev=save;
    save=save->link;
  }
  if(save==NULL&&prev!=NULL&&pos==1)
   {
     insertend();
     return;
   }
  else if(save==first&&prev==first&&pos==1)
   {
     insertbeg();
     return;
   }
if(pos==1)
   {
  printf("Enter roll no : ");
  scanf("%d",&(temp->roll));
    if(next!=NULL)
  {
    while(next!=NULL)
    {
      if(next->roll==temp->roll)
      {
        printf("\nRoll no. already exists\n");
        return;
      }
      next=next->link;
    }
  }
  printf("Enter Name : ");
  scanf("%s",temp->name);
  printf("enter cgpa : ");
  scanf("%f",&(temp->cg));
  
      prev->link=temp;
    temp->link=save;
   }
  else
    printf("\nInvalid position\n");
}
void deletebeg()
{
  if(first==NULL)
    {
     printf("\nEmpty list\n");
     return;
    } 
  first=first->link;
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
    save=save->link;
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
      save=save->link;
    }
    prev->link=save->link;
}
void deletebet()
{
  int pos,len=0;
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *save=first,*prev=first;
  while(save!=NULL)
  {
	len++;
    save=save->link;
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
      save=save->link;
    }
    prev->link=save->link;
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
    temp=temp->link;
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
  temp=temp->link;
 }if(flag==0)
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
    temp=temp->link;
  }
  if(flag==0)
  printf("\nRecord doesnt exist\n");
}
void display()
{
struct node *temp=first;
if(first==NULL)
printf("empty list\n");
else
  while(temp!=NULL)
  {
      printf("roll no : %d\t",temp->roll);
      printf("Name : %s\t",temp->name);
      printf("cgpa : %f\n\n",temp->cg);
    temp=temp->link;      
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
//printf("\n\nenter choice\n1.insertbeg\n2.insertend\n3.insertbet\n4.deletebeg\n5.deletend\n6.deletebet\n7.searchroll\n8.searchname\n9.searchcgpa\n10.display\n11.exit");


}}













