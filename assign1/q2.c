/***********************************************************

   Program to find the second largest and the second 
   smallest element of the array

 Author: leonatwork(Noel Aby Das)

**********************************************************/


#include<stdio.h>
void minmax(int a[],int n)
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-1;j++)
     {
       if(a[j]>a[j+1])
         {
           temp=a[j];
           a[j]=a[j+1];
	   a[j+1]=temp;
         }
     } 
  }
  int m=a[n-1],n1=a[0];
  for(i=n-1;i>=0;i--)  
  {
      if(a[i]<m)
       {m=a[i];break;}
    
  }
  for(i=0;i<n;i++)
  {
     if(a[i]>n1)
     {
      n1=a[i];
      break;
     }
  }
if(m==n1)
 printf("No second max or second min element\n");
else
 printf("second max element : %d\nsecond min element : %d\n",m,n1);	
}
void main()
{
int a[10],n,i;
label:
printf("enter the size of array : ");
scanf("%d",&n);
if(n<1)
{
printf("Invalid size\nEnter again\n");
goto label;
}
else if(n>10)
{
 printf("Array size too large\nenter smaller value\n");
 goto label;
}
printf("enter %d elements : \n",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
minmax(a,n);
}
