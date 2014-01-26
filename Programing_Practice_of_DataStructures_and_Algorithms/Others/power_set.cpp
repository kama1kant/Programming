#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    powerset(a, n);
    return 0;
}

void powerset(int a[], int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            for(k=0;count<i;k++)
            {

            }
        }
    }
}
