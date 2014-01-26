#include<iostream>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
    int n, k, min, sum=0;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(i==0)
            min = a[i];
        cin>>a[i];
        if(min>a[i])
            min = a[i];
        sum += a[i];
    }
    cout<<sum-(n*min);


    return 0;
}

