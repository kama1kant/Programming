#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string.h>

using namespace std;

void matrixRotation(int a[][3] , int size)
{
int i, j;
for(i=0; i<size ;i++)
{
	for(j=i+1; j<size ; j++)
	{
	int temp=a[i][j];
	a[i][j]=a[j][i];
	a[j][i]=temp;
	}
}

for(i=0; i<size/2 ;i++)
{
	for(j=0 ;j<size ;j++)
	{
	int temp=a[j][i];
	a[j][i]=a[j][size-i-1];
	a[j][size-i-1]=temp;

	}

}
return ;
}

int main()
{
    int a[3][3]={{1,2,3}, {5,6,7}, {9,10,11}};
  matrixRotation(a, 3);
  int size=3;
  for(int i=0 ; i<size ;i++)
   {
       for(int j=0; j<size ;j++)
        cout<<a[i][j]<<" ";
        cout<<"\n";
   }


}
