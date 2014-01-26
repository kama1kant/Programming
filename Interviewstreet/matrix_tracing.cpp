#include<iostream>
#include<cmath>
using namespace std;
long long calculate_path(long long m, long long n);

int main()
{
    long long t, m, n;
    cin>>t;
    for(long long q=0;q<t;q++)
    {
        cin>>m>>n;
        cout<<calculate_path(m, n)<<endl;
    }
    return 0;
}

long long calculate_path(long long m, long long n)
{
    long long mod = pow(10, 9)+7;
    long long *a = new long long[n];
    for(long long i=0;i<n;i++)
        a[i] = 1;
    for(long long i=1;i<m;i++)
    {
        for(long long j=n-2;j>=0;j--)
        {
                a[j] = a[j] + a[j+1];
        }
    }
    long long x = a[0] % mod;
    delete[] a;
    return x;
}
