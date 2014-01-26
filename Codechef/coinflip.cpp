#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
int t,I, N ,Q ,G ,res=0;
cin>>t;
while(t--)
{
    cin>>G;
    while(G--)
    {
        res=0;
        scanf("%d %d %d" ,&I, &N, &Q);
        if(N/2==0)
        res=N/2;
        else
        {
            if(I==Q)
              res=((N+1)/2 -1);
            else
            res=((N+1)/2);
        }
        //printf("%d %d %d\n",I ,N,Q);
        printf("%d\n",res);
    }
}
    return 0;
}
