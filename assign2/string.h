/***********************************************************

 user defined string.h header file

Author: leonatwork(Noel Aby Das)

**********************************************************/



int length(char *str)      // LENGTH 1
{
int len=0;
while(*str!='\0')
{
str++;
len++;
}
return len;
}

void concat(char *str1,char *str2)	//CONCAT 2
{
int i,len=length(str1);
for(i=len;*str2!='\0';str2++,i++)
{
str1[i]=*str2;
}
str1[i]='\0';
}

int symposf(char *str,char sym)  	//SYMBOL FIRST SEARCH 3
{
int i=0;
while(*str!='\0')
{
if(*str==sym)
return i;
str++;
i++;
}
return -1;
}

int symposl(char *str,char sym) 	//SYMBOL LAST SEARCH 4
{
int pos=-1,i;
for(i=0;str[i]!='\0';i++)
{
if(str[i]==sym)
pos=i;
}
return pos;
}



void reverse(char *str)		//REVERSE STRING 9
{
char t;
int i,len=length(str);
for(i=len-1;i>=len/2;i--)
{
t=str[i];
str[i]=str[len-1-i];
str[len-1-i]=t;
}
}


void revcncat(char *str)	//REVERSE CONCAT 5
{
int i;
char s[25];
for(i=0;str[i]!='\0';i++)
{
s[i]=str[i];
}
s[i]='\0';
reverse(s);
concat(str,s);
}


void dupconcat(char *str)    //DUPLICATE CONCAT  6
{
int i;
char dup[25];
for(i=0;i<length(str);i++)
{
dup[i]=str[i];
}
dup[i]='\0';
concat(str,dup);
}

int strcmp(char *str1,char *str2)	//STRING COMPARE 7
{
int i,len1=length(str1),len2=length(str2);
if(len1==len2)
{for(i=0;i<len1;i++)
{
if(str1[i]!=str2[i])
return -1;
}return 0;}
else
return -1;
}

void upper(char *str)		//TO UPPERCASE 10
{
int i;
for(i=0;str[i]!='\0';i++)
{
if(str[i]>=97&&str[i]<=122)
str[i]=str[i]-32;
}
}

void lower(char *str)		//TO LOWERCASE 11
{
int i;
for(i=0;str[i]!='\0';i++)
{
if(str[i]>=65&&str[i]<=91)
str[i]=str[i]+32;
}
}

void titlecs(char *str)        //TITLE CASE 12
{
int i;
lower(str);
for(i=0;str[i]!='\0';i++)
{
if(i==0&&(str[i]>=97&&str[i]<=122))
str[i]=str[i]-32;
else if((str[i]>=97&&str[i]<=122)&&str[i-1]==' ')
str[i]=str[i]-32;
}
}



int strcmpi(char *str1,char *str2)	//STRING COMPARE NOT CASE SENSITIVE  8
{
int i,len1=length(str1),len2=length(str2);
if(len1==len2)
{upper(str1);
upper(str2);
for(i=0;i<len1;i++)
{
if(str1[i]!=str2[i])
return -1;
}return 0;}
else
return -1;
}



int palinstr(char *str)		//PALINDROME STRING 15
{
int i,len=length(str);
for(i=len-1;i>=len/2;i--)
{
if(str[i]!=str[len-1-i])
return -1;
}
return 0;
}


void repsub(char *str,char *sub,int pos)    //SUBSTRING REPLACE 13
{
int i,len1=length(str),len2=length(sub),k=0;
if(pos-1+len2>len1)
printf("overflow\n");
else
for(i=pos-1;sub[k]!='\0';i++)
str[i]=sub[k++];
}

int subpos(char *str,char *sub)    //SUBSTRING SEARCH 14
{
int i,j,len1=length(str),len2=length(sub),k,f=0,p=0;
if(len1>=len2)
{
for(i=0;i<len1;i++)
{
if(str[i]==sub[0])
{
k=1;p=1;
if(i+len2-1<len1)
{
while(k<len2)
{
if(sub[k]==str[i+k])
k++;
else
{
f=1;p=0;
break;
}
}
if(f==0)
return i;
else
{
f=0;
continue;
}
}
else 
return -1;
}
}
if(p==0)
return -1;

}
else 
return -1;
}


int vowelcnt(char *str)		//VOWEL COUNT  16
{
int n=0,i=0;
while(str[i]!='\0')
{
switch(str[i])
{
case 'a':
case 'e':
case 'i':
case 'o':
case 'u':
case 'A':
case 'E':
case 'I':
case 'O':
case 'U':n++;
}
i++;
}
return n;
}

void wordcnt(char *str)        //WORD AND CHARACTER COUNT  17
{
int w=0,c=0,i;
for(i=0;str[i]!='\0';i++)
{
if((str[i]>=97&&str[i]<=122)||(str[i]>=65&&str[i]<=91))
 c++;
}
for(i=1;str[i]!='\0';i++)
{
  if(str[i]==' ' && str[i-1]!=' ')
   w++;
}
if(str[i-1]!=' ')
w++;
printf("number of characters : %d\n",c);
printf("number of words : %d\n",w);
}












