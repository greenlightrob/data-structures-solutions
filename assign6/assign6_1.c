/***********************************************************
 
 Application of queue data structure
 
 Author: leonatwork(Noel Aby Das)
 
 **********************************************************/
#include<stdio.h>
#include<stdlib.h>

int queue[4],flight_id[4],id=0;

    int rear=-1,front=-1;

void enqueue(int dest)
{
    if ((front == 0 && rear == 3) ||
            (rear == front-1))
    {
        printf("\nQueue overflow");
        return;
    }

    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = dest;
        flight_id[rear] = id;
        id++;
    }

    else if (rear == 3 && front != 0)
    {
        rear = 0;
        queue[rear] = dest;
        flight_id[rear] = id;
        id++;
    }

    else
    {
        rear++;
        queue[rear] = dest;
        flight_id[rear] = id;
        id++;
    }
    printf("flight id = %d ",flight_id[rear]);
                switch(queue[rear])
                 {
                    case 1:
                    printf(" to Denver booked\n");
                    break;
                    case 2:
                    printf(" to Chicago booked\n");
                    break;
                    case 3:
                    printf(" to Houston booked\n");
                    break;
                    case 4:
                    printf(" to Dallas booked\n");
                    break;

                 }
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nQueue underflow\n");
        return;
    }

    int data = queue[front],f_id=flight_id[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == 3)
        front = 0;
    else
        front++;
    printf("flight id = %d ",f_id);
                switch(data)
                 {
                    case 1:
                    printf(" to Denver took off\n");
                    break;
                    case 2:
                    printf(" to Chicago took off\n");
                    break;
                    case 3:
                    printf(" to Houston took off\n");
                    break;
                    case 4:
                    printf(" to Dallas took off\n");
                    break;

                 }
}

void displayqueue()
{
    if (front == -1)
    {
        printf("\nNo flights available");
        return;
    }
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            {
                printf("flight id = %d ",flight_id[i]);
                switch(queue[i])
                 {
                    case 1:
                    printf(" to Denver\n");
                    break;
                    case 2:
                    printf(" to Chicago\n");
                    break;
                    case 3:
                    printf(" to Houston\n");
                    break;
                    case 4:
                    printf(" to Dallas\n");
                    break;

                 }
            }
    }
    else
    {
        for (int i = front; i < 4; i++)
            {
                printf("flight id = %d ",flight_id[i]);
                switch(queue[i])
                 {
                    case 1:
                    printf(" to Denver\n");
                    break;
                    case 2:
                    printf(" to Chicago\n");
                    break;
                    case 3:
                    printf(" to Houston\n");
                    break;
                    case 4:
                    printf(" to Dallas\n");
                    break;

                 }
            }

        for (int i = 0; i <= rear; i++)
            {
                printf("flight id = %d ",flight_id[i]);
                switch(queue[i])
                 {
                    case 1:
                    printf(" to Denver\n");
                    break;
                    case 2:
                    printf(" to Chicago\n");
                    break;
                    case 3:
                    printf(" to Houston\n");
                    break;
                    case 4:
                    printf(" to Dallas\n");
                    break;

                 }
            }
    }
}

int main()
{
   int ch,dest;
   printf("\n\nMenu\n1. Book a flight\n2. Ride now\n3. Display runway\n4. Exit\n\n");
   label:
   printf("Enter your choice : ");
   scanf("%d",&ch);
   if(!(ch>0&&ch<5))
    {
        printf("Invalid choice\n");
        goto label;
    }
   while(1)
   {
   switch(ch)
   {
    case 1:
    {
        printf("\n\nSelect destination\n1.Denver\n2.Chicago\n3.Houston\n4.Dallas\n\n");
        printf("Enter the no. : ");
        scanf("%d",&dest);
        if(dest>0&&dest<5)
        enqueue(dest);
        else
            printf("\nInvalid choice\n");
   }
   break;
   case 2:
    {
        dequeue();
    }
    break;
    case 3:
    {
        displayqueue();
    }
    break;
    case 4:
    {
        exit(1);
    }
   }
   printf("\n\nMenu\n1. Book a flight\n2. Ride now\n3. Display runway\n4. Exit\n\n");
   printf("Enter your choice : ");
   scanf("%d",&ch);
   if(!(ch>0&&ch<5))
    {
        printf("\nInvalid choice\n");
        goto label;
    }
}

    return 0;
}
