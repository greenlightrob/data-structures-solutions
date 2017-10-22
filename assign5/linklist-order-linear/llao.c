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
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  if(first!=NULL)
  {
    printf("\nRoll no. should be less than %d to insert at the beginning\n",first->roll);
  }
  printf("Enter roll no 1: ");
  scanf("%d",&(temp->roll));
  if(first!=NULL&&temp->roll>=first->roll)
  {
    printf("This record cannot be entered at the start\n");
    return;
  }
  printf("Enter Name 1: ");
  scanf("%s",temp->name);
  printf("enter cgpa : ");
  scanf("%f",&(temp->cg));
  temp->link=first;
  first=temp;
  return;
}
void insert()
{
  struct node *save=first,*prev=first,*temp=(struct node*)malloc(sizeof(struct node));
  if(save==NULL)
  {
    insertbeg();
    return;
  }
  printf("Enter roll no : ");
  scanf("%d",&(temp->roll));
  while(save->link!=NULL&&save->roll<temp->roll)
  {
    prev=save;
    save=save->link;
  }
  printf("Enter Name : ");
  scanf("%s",temp->name);
  printf("enter cgpa : ");
  scanf("%f",&(temp->cg));
     if(save->roll==temp->roll)
     {
      printf("\nThe roll no. already exist");
      return;
     }
     else if (save->roll>temp->roll)
     {
       if(prev==save)
       {
        temp->link=save;
        first=temp;
        return;
       }
       prev->link=temp;
       temp->link=save;
       return;
     }
     else if(save->roll<temp->roll)
     {
      save->link=temp;
      temp->link=NULL;
      return;
     }
}
void insertend()
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *save=first;
   if(save!=NULL)
  {
  while(save->link!=NULL)
  {
    save=save->link;
  }
      printf("\nRoll no. should be greater than %d to insert at the end\n",save->roll);

}
  else insertbeg();
  printf("Enter roll no : ");
  scanf("%d",&(temp->roll));
   if(temp->roll<=save->roll)
  {
    printf("This record cannot be entered at the end\n");
    return;
  }
  printf("Enter Name : ");
  scanf("%s",temp->name);
  printf("enter cgpa : ");
  scanf("%f",&(temp->cg));
  temp->link=NULL;
  save->link=temp;
}
void insertbet()
{
  int pos;
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *save=first,*prev=first;
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
  printf("\nRoll no. should be greater than %d and less than %d to insert at that position\n",prev->roll,save->roll);
  printf("Enter roll no : ");
  scanf("%d",&(temp->roll));
 if(temp->roll>=save->roll||temp->roll<=prev->roll)
  {
    printf("This record cannot be entered at that position\n");
    return;
  }
  printf("Enter Name : ");
  scanf("%s",temp->name);
  printf("enter cgpa : ");
  scanf("%f",&(temp->cg));
  
      prev->link=temp;
    temp->link=save;
   }
  else
  {
    printf("\nInvalid position\n");
    return;
  }
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
  while(temp!=NULL&&temp->roll<=r)
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
printf("enter choice\n1.insert\n2.insertbeg\n3.insertend\n4.insertbet\n5.deletebeg\n6.deletend\n7.deletebet\n8.searchroll\n9.searchname\n10.searchcgpa\n11.display\n12.exit");
while(1)
{
printf("\nenter choice : ");
scanf("%d",&n);
printf("\n");
switch(n)
{
  case 1:
  insert();
  break;
 case 2:
  insertbeg();
  break;
 case 3:
  insertend();
  break;
 case 4:
  insertbet();
  break;
 case 5:
  deletebeg();
  break;
 case 6:
  deletend();
  break;
 case 7:
  deletebet();
  break;
 case 8:
  searchroll();
  break;
 case 9:
  searchname();
  break;
 case 10:
  searchcgpa();
  break;
 case 11:
  display();
  break;
 case 12:
  exit(1);
}

}}













