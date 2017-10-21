/***********************************************************

 		Program to evaluate postfix expression

Author: leonatwork(Noel Aby Das)

**********************************************************/


#include<stdio.h>
#define max 100
struct stack
{
float a[max];
int top;
}s;
//s.top=-1;
void push(float n)
{
s.a[++s.top]=n;
}
float pop()
{
s.top--;
return s.a[s.top+1];
}
void main()
{
char str[25];
float var,j,k;
int i;
s.top=-1;
printf("Enter the postfix expression : ");
scanf("%s",str);
for(i=0;str[i]!='\0';i++)
{
if(str[i]>='0'&&str[i]<='9')
push((int)str[i]-48);
else if(str[i]=='+')
    {var=pop()+pop();
    push(var);}
   else if(str[i]=='-')
    {var=pop()-pop();
    push(-var);}
   else if(str[i]=='*')
    {var=pop()*pop();
    push(var);}
   else if(str[i]=='/')
    { j=pop();k=pop();
     var=k/j;
    push(var);}
   else if(str[i]=='^')
    { j=pop();k=pop();var=1;
     while(j>0)
      {var*=k;j--;}
    push(var);}
   else if(str[i]=='%')
    { j=pop();k=pop();
     var=(int)k%(int)j;
    push(var);}
 }

var=pop();
printf("Result = %f\n",var);
}
