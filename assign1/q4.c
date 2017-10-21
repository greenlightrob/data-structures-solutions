/***********************************************************

 Program to delete an element at a given index of an array

 Author: leonatwork(Noel Aby Das)

**********************************************************/


#include<stdio.h>
void main()
{
int a[20],n,i,p,y;
char in;
label:
printf("enter the size of array : \n");
scanf("%d",&n);
if(n<1)
{
printf("Invalid size\nEnter again\n");
goto label;
}
else if(n>20)
{
 printf("Array size too large\nenter smaller value\n");
 goto label;
}
printf("enter %d elements of array : \n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
label1:
   printf("enter the position of element you want to delete : ");
   scanf("%d",&p);
   if(p>n||p<1)
   {
   printf("Invalid position\n");
   goto label1;
   }
   else {
   for(i=p-1;i<n-1;i++)
    {
     a[i]=a[i+1];
    }
     n--;}
   printf("the new array after deletion is : ");
   for(i=0;i<n;i++)
   printf("%d ",a[i]);
   if(n==0)
   {
     printf("empty array\n");
    }

}
