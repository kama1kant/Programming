#include<iostream>
#include<cmath>
using namespace std;
long long calculate_path(long long m, long long n);
long long factorial(long long n);

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
    if(n>m)
    {
         long long temp = m;
         m = n;
         n = temp;
    }
    long long mod = pow(10, 9)+7;
    long long numerator = m-1+n-1;
    long long multiply = numerator;
    for(long long i=0;i<n-2;i++)
    {
         multiply = multiply*(numerator-1);
         numerator--;
    }
    numerator = multiply;
    long long denominator = factorial(n-1);
    return ((numerator/denominator)%mod);
}

long long factorial(long long n)
{
    long long x = 1;
    for(long long i=1;i<=n;i++)
        x *= i;
    return x;
}
