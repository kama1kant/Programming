#include<stdio.h>
int isSubset(char *a, char *b);

int main()
{
char str1[]="apple";
char str2[]="applle";

if(isSubset(str1, str2)==0)
{
printf("\nYes, characters in B=[%s] are a subset of characters in A=[%s]\n",str2,str1);
}
else
{
printf("\nNo, characters in B=[%s] are not a subset of characters in A=[%s]\n",str2,str1);
}

getch();
return(0);
}


// Function to check if characters in "b" are a subset
// of the characters in "a"

int isSubset(char *a, char *b)
{
int letterPresent[256];
int i;

for(i=0; i < 256; i++)
letterPresent[i]=0;

for(i=0; a[i]!='\0'; i++)
letterPresent[a[i]]++;

for(i=0; b[i]!='\0'; i++)
if(--letterPresent[b[i]]<0)
return(1);

return(0);
}
