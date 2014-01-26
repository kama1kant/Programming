#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int t;
    double x, y, a, ds, dt, d;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        scanf("%lf%lf%lf", &ds, &dt, &d);
        if((ds+dt)>=d)
        printf("%f\n", 0);
        else
        {
            x = ds;
            y = d-dt;
            if(x>y)
                a = x-y;
            else
                a = y-x;
        printf("%f\n", a);
        }
    }
    return 0;
}
