#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#define MOD 1000000007

using namespace std;

int bitset(int n)
{
    int count=0;
    for(int i=0;i<32;i++)
    {
        if(n&(1<<i))
        count++;
    }
    return count;
}

    int a[1000000];
int main()
{
    int t, n, m;
    a[0]=1;
    a[1]=2;
    for(int i=2;i<=1000000;i++)
    {
        a[i] = (a[i-1]+a[i-2])%MOD;
    }
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        if(bitset(a[n-1]) == m)
        cout<<"CORRECT\n";
        else
        cout<<"INCORRECT\n";
    }
    return 0;
}
