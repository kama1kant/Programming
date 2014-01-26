#include<iostream>
#include<cmath>

using namespace std;
long long check_fibo(long long n);
long long is_perfect_square(long long x);
long long PerfectSquare(long long n);

int main()
{
    long long t, n;
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

long long check_fibo(long long n)
{
    long long x = (long long)5*n*n+4;
    long long y = (long long)5*n*n-4;

    //return (is_perfect_square(x) || is_perfect_square(y));
    return (PerfectSquare(x) || PerfectSquare(y));

}

long long PerfectSquare(long long n)
{
    long long h = n & 0xF; // last hexidecimal "digit"
    if (h > 9)
        return 0; // return immediately in 6 cases out of 16.

    // Take advantage of Boolean short-circuit evaluation
    if ( h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8 )
    {
        // take square root if you must
        long long t = (long long) floor( sqrt((double) n) + 0.5 );
            return t*t == n;
    }
    return 0;
}

long long is_perfect_square(long long x)
{
    long double temp = (long long)sqrt(x);
    if(temp*temp == x)
        return 1;
    else
        return 0;
}
