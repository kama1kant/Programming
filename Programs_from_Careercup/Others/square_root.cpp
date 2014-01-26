#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
double msqrt(double number);
int max(double a, double b);

int main()
{
    cout<<msqrt(25);
    return 0;
}


double msqrt(double number)
{
    const double EPS = 0.0001;
    double left = 0.0, right = max(1, number), mid;
    while (left + EPS < right)
    {
        mid = (left + right) / 2.0;
        if(mid*mid == number)
            return mid;
        if (mid * mid > number)
            right = mid;
        else
           left = mid;
    }
    return left;
}

int max(double a, double b)
{
    if(a>b)
        return a;
    else
        return b;
}
