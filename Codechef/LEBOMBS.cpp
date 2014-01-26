#include<iostream>
using namespace std;

int main()
{
    int t=0 ,n=0 ,i=0 ,l=0 ,count=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        char A[1000];
        cin>>A;
        count=0;
        for(i=0 ;i<n ;i++)
        {
            if(i==0 && A[i]!='1' && A[i+1]!='1')
                count++;
            else if(i==n-1 && A[i]!='1' && A[i-1]!='1')
                count++;
            else if(A[i]!='1' && A[i+1]!='1' && A[i-1]!='1')
                count++;
        }
        cout<<count<<endl;
    }
return 0;
}
