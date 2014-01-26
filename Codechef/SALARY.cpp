#include <iostream>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n, min, count=0;
        int w[10000];
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>w[j];
            if(j==0)
                min=w[j];
            else if(min>w[j])
                min=w[j];
        }
        for(int k=0;k<n;k++)
        {
            count +=w[k]-min ;
        }
        cout<<count<<"\n";

    }
    return 0;
}
