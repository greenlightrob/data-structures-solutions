
/***********************************************************

 Program to check the user defined header file string.h

Author: leonatwork(Noel Aby Das)

**********************************************************/


#include<stdio.h>
#include<stdlib.h>
#include "string.h"
void main()
{
char str[25];

printf("*****TITLE CASE*****\n");
printf("enter string : ");
gets(str);
titlecs(str);
printf("title case string : %s\n\n\n",str);

printf("*****WORD and CHARACTER COUNT******\n");
printf("enter string : ");			
gets(str);
wordcnt(str);

}
