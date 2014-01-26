#include<iostream>
#include<stdio.h>

using namespace std;


int main()
{
    int n, k, x, count=0;
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &x);
        if(x%k == 0)
        count++;
    }
    cout<<count;

    return 0;
}
