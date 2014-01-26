#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

void multiply(long long F[2][2], long long M[2][2]);
void power(long long F[2][2], long long n);
long long fib(long long n);

long long check_fibo(long long n)
{
    long long x = 0;
    long long num = 1;
    while(x < n)
    {
        x = fib(num);
        //cout<<num<<" "<<x<<"\n";
        if(x > n)
            return 0;
        else if(x == n)
            return 1;
        else
            num++;
    }
}
long long fib(long long n)
{
  long long F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}

/* Optimized version of power() in method 4 */
void power(long long F[2][2], long long n)
{
  if( n == 0 || n == 1)
      return;
  long long M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(long long F[2][2], long long M[2][2])
{
  long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

int main()
{
    long t, n;
    cin>>t;
    for(long long q=0;q<t;q++)
    {
        cin>>n;
        if(check_fibo(n))
            cout<<"IsFibo\n";
        else
            cout<<"IsNotFibo\n";
    }
    return 0;
}
