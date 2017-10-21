/***********************************************************

 Program to implement a stack of book (containing book name,
 cost, book_id) using array implementation if stack

Author: leonatwork(Noel Aby Das)

**********************************************************/

#include<stdio.h>
#include<stdlib.h>
#define max 100
struct bookStack 
{
	int book_id[max];
	char book_name[max][10];
	float book_price[max];
	int top;
}s;

void push( int id , char *name , float cost )
{
	if(s.top==max-1)
		{
			printf("Stack overflow\n");
			return;
		}
	else
	    {
	    	s.book_id[++s.top]=id;
	    	int i=0;
	    	while(name[i]!='\0')
	    	{
	    	s.book_name[s.top][i]=name[i];
	    	i++;
	    	}
	    	s.book_name[s.top][i]='\0';
	    	s.book_price[s.top]=cost; 
	    }	
		

}	

void pop()
{
	if(s.top==-1)
	{
		printf("Stack underflow\n");
	}
	else
	{
	 printf("popped book id = %d name= %s cost = %f\n",s.book_id[s.top],s.book_name[s.top],s.book_price[s.top]);
	 s.top--;
	 }
}

void peep()
{
	if(s.top==-1)
		printf("empty stack\n");
	else
	    {
	     	printf("id= %d name = %s cost = %f\n ",s.book_id[s.top],s.book_name[s.top],s.book_price[s.top]);
	    }	
}

int main()
{
   s.top=-1;
   int choice=0,bid,n=0;
   float bcost;
   char ch='y',bname[10];
   while(n==0)
   {
     printf("\n\n/***OPTIONS***/ :\n1.PUSH \n2.POP \n3.PEEP \n4.Exit\n");
     printf("Enter your choice : ");
     scanf("%d",&choice);
   		switch(choice)
   		{
   			case 1:
   			{
   				printf("\nPUSH\nenter book id : ");
   				scanf("%d",&bid);
   				printf("enter book name : ");
   				scanf("%s",bname);
   				printf("enter book cost : ");
   				scanf("%f",&bcost);
   				push(bid,bname,bcost);
   				break;
   			}
   			case 2:
   			{
   			    
   				printf("\nPOP\n");
   				pop();
   				break;
   				
   			}
   			case 3:
   			{
   				printf("\nPEEP\n");
   			 	peep();
   			 	break;
   			}
			default :
				exit(1);
   		}

   }

	return 0;
}



