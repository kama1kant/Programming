#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string>
#include<stack>
#define N 100

using namespace std;
void rotate_matrix(int **a, int n);


int main()
{
    int n;
    cin>>n;
    int **a = new int*[3];
    for(int i=0;i<3;i++)
    {
        a[i] = new int[3];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    rotate_matrix(a, 3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

void rotate_matrix(int **a, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<3;j++)
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp = a[j][i];
            a[j][i] = a[j][n-i-1];
            a[j][n-i-1] = temp;
        }
    }
}
