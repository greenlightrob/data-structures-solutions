/***********************************************************

 Program to check the user defined header file string.h

Author: leonatwork(Noel Aby Das)

**********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "string.h"
void main()
{
int len,pos,b,*p;
char sym,str[25],str1[25],str2[25],str3[25];

printf("/*********LENGTH OF STRING*******/\n");
printf("enter string : ");
scanf("%s",str);
len=length(str);
printf("length of string : %d\n\n\n",len);

printf("/*********CONCATENATION OF TWO STRINGS*******/\n");
printf("enter string 1 : ");
scanf("%s",str1);
printf("enter string 2 : ");
scanf("%s",str2);
concat(str1,str2);
printf("After concatenation string 1 is : %s\n\n\n",str1);


printf("/*********SYMBOL FIRST SEARCH*******/\n");
printf("Enter string : ");
scanf("%s",str3);
printf("enter the symbol you want to find : ");
scanf("%s",&sym);
pos=symposf(str3,sym);
if(pos==-1)
printf("symbol not present\n");
else
printf("symbol present at index : %d\n\n\n",pos);

printf("/*********SYMBOL LAST SEARCH*******/\n");
printf("Enter string : ");
scanf("%s",str3);
printf("enter the symbol you want to find : ");
scanf("%s",&sym);
pos=symposl(str3,sym);
if(pos==-1)
printf("symbol not present\n\n\n");
else
printf("symbol present at index : %d\n\n\n",pos);


printf("/*********REVERSE OF STRING*******/\n");
printf("enter string : ");
scanf("%s",str);
reverse(str);
printf("reverse string : %s\n\n\n",str);

printf("/*********REVERSE CONCATENATION*******/\n");
printf("enter string : ");
scanf("%s",str);
revcncat(str);
printf("After reverse concat : %s\n\n\n",str);

printf("/*********DUPLICATE CONCATENATE*******/\n");
printf("enter string : ");
scanf("%s",str);
dupconcat(str);
printf("After duplicate concat : %s\n\n\n",str);

printf("/*********STRING COMPARE*******/\n");
printf("enter string 1 : ");
scanf("%s",str1);
printf("enter string 2 : ");
scanf("%s",str2);
b=strcmp(str1,str2);
if(b==0)
printf("Same strings\n");
else
printf("Different strings\n\n\n");

printf("/*********UPPERCASE*******/\n");
printf("enter string : ");
scanf("%s",str);
upper(str);
printf("new uppercase string : %s\n\n\n",str);

printf("/*********STRING COMPARE (CASE INSENSITIVE)*******/\n");
printf("enter string 1 : ");
scanf("%s",str1);
printf("enter string 2 : ");
scanf("%s",str2);
b=strcmpi(str1,str2);
if(b==0)
printf("Same strings\n");
else
printf("Different strings\n\n\n");


printf("/*********LOWERCASE*******/\n");
printf("enter string : ");
scanf("%s",str);
lower(str);
printf("new lowercase string : %s\n\n\n",str);

printf("/*********PALINDROME CHECK*******/\n");
printf("enter string : ");
scanf("%s",str);
b=palinstr(str);
if(b==0)
printf("Its a palindrome\n");
else
printf("Its not a palindrome\n\n\n");


printf("/*********SUBSTRING SEARCH*******/\n");
printf("enter string 1 : ");
scanf("%s",str1);
printf("enter string 2 : ");
scanf("%s",str2);
b=subpos(str1,str2);
if(b==-1)
printf("not found\n");
else
printf("found at index : %d\n\n\n",b);


printf("/*********COUNT VOWELS*******/\n");
printf("enter string : ");
scanf("%s",str);
b=vowelcnt(str);
printf("No. of vowels : %d\n\n\n",b);

printf("/*********SUBSTRING REPLACE*******/\n");
printf("enter string : ");
scanf("%s",str1);
printf("enter substring : ");
scanf("%s",str2);
printf("enter position : ");
scanf("%d",&pos);
repsub(str1,str2,pos);
printf("new string : %s\n\n\n",str1);
/*
Run seperately...
Put the remaining code in the comments & 
only then run the below portion

printf("*********TITLE CASE*******\n");
printf("enter string : ");
gets(str);
titlecs(str);
printf("title case string : %s\n\n\n",str);

printf("*********WORD AND CHARACTER COUNT*******\n");
printf("enter string : ");			
gets(str);
wordcnt(str);
*/
}
