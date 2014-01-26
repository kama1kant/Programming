#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define N 100
using namespace std;

int sum(int a[], int n, int it);


int main()
{
    int a[N];
    int n, it;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>it;
    cout<<sum(a, n, it);
    return 0;
}

int sum(int a[], int n, int it)
{
    for(int i=0;i<it;i++)
    {
        if(n-i>0)
        {
            for(int j=0;j<n-i-1;j++)
            {
                a[j] = a[j+1]- a[j];
            }
        }
    }
    if(it>=n)
    {
        return a[0];
    }
    else
    {
        int sum=0;
        for(int i=0;i<n-it;i++)
        {
            sum+=a[i];
        }
        return sum;
    }
}
