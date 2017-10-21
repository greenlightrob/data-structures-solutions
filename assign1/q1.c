/***********************************************************

   Program to find the largest and the smallest element 
   of the array

 Author: leonatwork(Noel Aby Das)

**********************************************************/


#include<stdio.h>
void minmax(int a[],int n)
{
  int min,max,i,j;
  min=max=a[0];
  for(i=1;i<n;i++)
   {
     if(a[i]>max)
	max=a[i];
     if(a[i]<min)
	min=a[i];	
   }
printf("maximum element : %d\nminimum element : %d\n",max,min);
}
void main()
{
int a[10],i,n;
label:
printf("Enter the number of elements in array : ");
scanf("%d",&n);
if(n<=0)
{
  printf("Invalid size\nEnter again\n");
  goto label;
}
else if(n>10)
{
 printf("Array size too large\nenter smaller value\n");
 goto label;
}
printf("Enter %d elements : \n",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
minmax(a,n);
}
