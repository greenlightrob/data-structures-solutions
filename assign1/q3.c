/***********************************************************

 Program to insert an element at a given index of an array

 Author: leonatwork(Noel Aby Das)

**********************************************************/


#include<stdio.h>
void main()
{
int a[25],n,i,p,q;
label:
printf("enter the size of array : ");
scanf("%d",&n);
if(n<1)
{
printf("Invalid size\nEnter again\n");
goto label;
}
else if(n>25)
{
 printf("Array size too large\nenter smaller value\n");
 goto label;
}
printf("enter %d elements : \n",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter the number you want to insert : ");
scanf("%d",&q);
pslabel:
printf("enter the postion of insertion : ");
scanf("%d",&p);
if(p>n+1||p<0)
{
printf("Invalid position\nEnter again\n");
goto pslabel;
}
if(n==25)
{
printf("overflow\n");
}
else{
for(i=n;i>=p;i--)
{
  a[i]=a[i-1];
}
a[p-1]=q;
printf("the new array is : ");
for(i=0;i<n+1;i++)
{
  printf("%d ",a[i]);
}
printf("\n");
}
}
