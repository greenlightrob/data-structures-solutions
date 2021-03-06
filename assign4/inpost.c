/***********************************************************

 Program to convert infix expression to postfix form

Author: leonatwork(Noel Aby Das)

**********************************************************/

#include<stdio.h>
#define max 100
struct stack
{
   char operator[max];
   int top;
}s;
void pop()
    {
      
     printf("%c",s.operator[s.top--]);
   
    }
void push(char str)
	{
       if(s.top>-1&& s.operator[s.top]!='(' &&( (str=='+' && s.operator[s.top]=='/')||(str=='+' && s.operator[s.top]=='*')||(str=='-' && s.operator[s.top]=='/')||(str=='-' && s.operator[s.top]=='*')||(str=='*' && s.operator[s.top]=='/')||(str=='/' && s.operator[s.top]=='*')|| (str=='+' && s.operator[s.top]=='^')|| (str=='-' && s.operator[s.top]=='^')||(str=='+' && s.operator[s.top]=='%')||(str=='-' && s.operator[s.top]=='%')||(str=='%' && s.operator[s.top]=='/')||(str=='/' && s.operator[s.top]=='%')||(str=='*' && s.operator[s.top]=='%')||(str=='%' && s.operator[s.top]=='*')||(str=='*' && s.operator[s.top]=='^')||(str=='/' && s.operator[s.top]=='^')||(str=='%' && s.operator[s.top]=='^')||(str==s.operator[s.top])))
        {
          do{pop();}while(s.top>-1&&s.operator[s.top]!='('&&((str==s.operator[s.top])||(str=='+' && s.operator[s.top]=='-')||(str=='-' && s.operator[s.top]=='+')));
        }
	   s.operator[++s.top]=str;
        
	}
void main()
{
	char exp[25];
	int i;
	s.top=-1;
	printf("enter the infix expression : ");
	scanf("%s",exp);
    printf("postfix expression : ");
	
	for(i=0;exp[i]!='\0';i++)
	{
       if(!(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'|| exp[i]=='%' ||exp[i]=='(' || exp[i]==')'))
         printf("%c",exp[i]);
       else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'|| exp[i]=='%' ||exp[i]=='(' )
        push(exp[i]);
       else if(exp[i]==')')
         {
			while(s.operator[s.top]!='(')
			{pop();
				}s.top--;
		 }
	}
   while(s.top>-1)
    pop();
printf("\n");
}
