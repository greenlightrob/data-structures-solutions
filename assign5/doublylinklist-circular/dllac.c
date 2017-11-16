/***********************************************************
 
    Doubly circular linked list
 
 Author: leonatwork(Noel Aby Das)
 
 **********************************************************/
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int roll;
 char name[25];
 float cg;
 struct node *rptr;
 struct node *lptr;
};
struct node *first=NULL;
void insertbeg()
{
  struct node *next=first,*q,*temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter roll no : ");
  scanf("%d",&(temp->roll));
    if(next!=NULL)
  {
    do{
      if(next->roll==temp->roll)
      {
        printf("This roll no. already exists\n");
        return;
      }
      next=next->rptr;
    }while(next!=first);
  }
  printf("Enter Name : ");
  scanf("%s",temp->name);
  printf("enter cgpa : ");
  scanf("%f",&(temp->cg));
  temp->rptr=first;
  q=first;
  first=temp;
  struct node *save=first;
  if(first->rptr==NULL)
  {
   first->rptr=first;
   first->lptr=first;
	}
  else if(first->rptr!=NULL)
   {
		do{
			save=save->rptr;
			}while(save->rptr!=q);
	save->rptr=first;
  first->lptr=save;
   }
}

void insertend()
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *save=first,*next=first;
  if(first==NULL)
   {
	insertbeg();
	return;
	}
  printf("Enter roll no : ");
  scanf("%d",&(temp->roll));
  if(next!=NULL)
  {
    do{
      if(next->roll==temp->roll)
      {
        printf("This roll no. already exists\n");
        return;
      }
      next=next->rptr;
    }while(next!=first);
  }
  printf("Enter Name : ");
  scanf("%s",temp->name);
  printf("enter cgpa : ");
  scanf("%f",&(temp->cg));
  while(save->rptr!=first)
  {
    save=save->rptr;
  }
  save->rptr=temp;
  temp->lptr=save;
  temp->rptr=first;
  
}
void insertbet()
{
  int pos,len=0;
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *save=first,*prev=first,*next=first;
  printf("Enter the position : ");
  scanf("%d",&pos);
  if(pos==1)
   {
	insertbeg();
	return;
	}
  else if(save==NULL&&pos>1)
   {
	printf("\nInvalid position\n");
return;
	}
  while(save->rptr!=first)
  {
   len++;
   save=save->rptr;
  }
len=len+2;
if(pos>=len+1||pos<1)
{
printf("\nInvalid position\n");
return;
}
else if(pos==len+1)
{
  insertend();
  return;
}save=first;
while(pos>1)
{
	pos--;
    prev=save;
    save=save->rptr;
  }
  printf("Enter roll no : ");
  scanf("%d",&(temp->roll));
  if(next!=NULL)
  {
    do{
      if(next->roll==temp->roll)
      {
        printf("This roll no. already exists\n");
        return;
      }
      next=next->rptr;
    }while(next!=first);
  }
  printf("Enter Name : ");
  scanf("%s",temp->name);
  printf("enter cgpa : ");
  scanf("%f",&(temp->cg));
  
      prev->rptr=temp;
      temp->lptr=prev;
    temp->rptr=save;
    save->lptr=temp;
}
void deletebeg()
{
  if(first==NULL)
    {
     printf("\nEmpty list\n");
     return;
    } 
  else if(first->rptr==first)
   {
		first=NULL;
		return;
   }
  struct node *save=first;
	do{
		save=save->rptr;
	  }while(save->rptr!=first);
	save->rptr=first->rptr;
  (first->rptr)->lptr=save;
    first=first->rptr;
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
  do{
	len++;
    save=save->rptr;
  }while(save!=first);save=first;
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
    first->lptr=prev;
}
void deletebet()
{
  int pos,len=0;
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *save=first,*prev=first;
  
 printf("Enter the position : ");
  scanf("%d",&pos);
  if(pos==1)
   {
	deletebeg();
	return;
	}
  else if(save==NULL)
   {
	printf("\nEmpty list\n");
return;
	}
  while(save->rptr!=first)
  {
   len++;
   save=save->rptr;
  }
len=len+1;
if(pos>len||pos<1||(pos>1&&first->rptr==first))
{
printf("\nInvalid position\n");
return;
}
else if(pos==len)
{
  deletend();
  return;
}save=first;
while(pos>1)
{
	pos--;
    prev=save;
    save=save->rptr;
  }
prev->rptr=save->rptr;
(save->rptr)->lptr=prev;
 
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
  if(temp->rptr==temp)
  {
    if(temp->roll==r)
	 {printf("\nName : %s\tcgpa : %f\n",temp->name,temp->cg);
        return;}
    else{
		  printf("\nRecord doesnt exist\n");
        return;
      }
  }
  
  do{
	if(temp->roll==r)
     {
        printf("\nName : %s\tcgpa : %f\n",temp->name,temp->cg);
        return;
     }
    temp=temp->rptr;
  }while(temp!=first);
  printf("\nRecord doesnt exist\n");
}
void searchname()
{
 char str[25];
 int i,f=0,p=0;
 printf("Enter the name to be seached : ");
 scanf("%s",str);
 struct node *temp=first;
  


  if(first==NULL)
  {
    printf("empty list\n");
    return;
  }

do{
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
     p=1;
   }
  temp=temp->rptr;
 }while(temp!=first);
   if(p==0)
    printf("\nRecord not found\n");
}
void searchcgpa()
{
  int p=0;
  float c;
  printf("Enter the cgpa to be searched : ");
  scanf("%f",&c);
  struct node *temp=first;
  if(first==NULL)
  {
    printf("empty list\n");
    return;
  }
  if(temp->rptr==temp)
  {
    if(temp->cg==c)
	 {
        printf("\nRoll no : %d\tName : %s\n",temp->roll,temp->name);
        }
    else{
		  printf("\nRecord doesnt exist\n");
        return;
      }
  }
  
  do{
	if(temp->cg==c)
     {
        printf("\nRoll no : %d\tName : %s\n",temp->roll,temp->name);
         p=1;
     }
    temp=temp->rptr;
  }while(temp!=first);
  if(p==0)
    printf("\nRecord doesnt exist\n");
}
void display()
{
struct node *q,*temp=first;
if(first==NULL)
printf("empty list\n");
else if(first!=NULL)
{
q=temp;
  do
  {
      printf("roll no : %d\t",temp->roll);
      printf("Name : %s\t",temp->name);
      printf("cgpa : %f\n\n",temp->cg);
    temp=temp->rptr; 
  }while(temp!=q);
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













