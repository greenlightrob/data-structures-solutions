
/***********************************************************
 
         Application of queue data structure
 
 Author: leonatwork(Noel Aby Das)
 
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
int queue[4][4],front[4]={-1,-1,-1,-1},rear[4]={-1,-1,-1,-1},id=1;
void enqueue(int n)
{
	if((rear[n]==3&&front[n]==0) || (rear[n]==front[n]-1))
	{
		printf("\nOverflow\n");
		return;
	}
  else if(front[n]==-1)
    front[n]=rear[n]=0;  
  else if(rear[n] == 3 && front[n] != 0)
    rear[n]=0;
  else
    rear[n]++;
	queue[n][rear[n]]=id++;
 printf("\nFlight booked.... id : %d\n",queue[n][rear[n]]);
}
void dequeue(int n)
{
     if(front[n]==-1)
      {
        printf("\nNo current flights\n");
        return;
      }    
      int t=queue[n][front[n]];
     if(front[n]==rear[n])
     {
       front[n]=rear[n]=-1;
     }
     else if(front[n]==3)
     {
      front[n]=0;
     }
     else 
     {
      front[n]++;
     }
     printf("\nflight id : %d took off\n",t);
}
void main()
{
   int ch,dest;
   printf("\n\n\nMenu\n1. Book a flight\n2. Ride now\n3. Exit\n");
   printf("Enter your choice : ");
   scanf("%d",&ch);
   while(1)
   {
   switch(ch)
   {
   	case 1:
   	{
   		printf("\n\nSelect destination\n1.Denver\n2.Chicago\n3.Houston\n4.Dallas\n");
   		printf("Enter the no. : ");
   		scanf("%d",&dest);
     	enqueue(dest-1); 
   }
   break;
   case 2:
   	{
   		printf("\n\nSelect destination\n1.Denver\n2.Chicago\n3.Houston\n4.Dallas\n");
   		printf("Enter the no. : ");
   		scanf("%d",&dest);
     	dequeue(dest-1);
   	}
   	break;
   	case 3:
   	{
   		exit(1);
   	}
   }
   printf("\n\n\nMenu\n1. Book a flight\n2. Ride now\n3. Exit\n");
   printf("Enter your choice : ");
   scanf("%d",&ch);   
   }	
	
}
