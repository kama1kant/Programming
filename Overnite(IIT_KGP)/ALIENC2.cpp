#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
    int t;
    long long n;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld", &n);
        if((n!= 1) && (n&(n-1)))
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}
