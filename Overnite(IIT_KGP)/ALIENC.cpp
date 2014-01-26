#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{

    int t;
    long long n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int f=0;
        cin>>n;
        if(n==1)
        {
            cout<<"No\n";
        }
        else if(n%2!=0)
        {
            cout<<"Yes\n";
        }
        else
        {
            while(1)
            {
                if(n==1)
                {
                    cout<<"NO\n";
                    break;
                }
                if(n%2==0)
                {
                    n = n/2;
                }
                else
                {
                    n = (n*3)+3;
                    f=1;
                    break;
                }
            }
            if(f==1)
            {
                cout<<"Yes\n";
            }
        }
    }
    return 0;
}
