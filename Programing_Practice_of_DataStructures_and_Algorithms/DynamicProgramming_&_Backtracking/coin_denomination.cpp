#include<iostream>

using namespace std;
int coin_check(int a[], int size, int sum, int x);

int count = 0;
int main()
{
    int a[]={1, 2, 5, 10};
    coin_check(a, 4, 6,0);
    cout<<"\n"<<count;
    return 0;
}


int coin_check(int a[], int size, int sum, int x)
{
    if(sum == 0)
        count++;
    for(int i=x;i<size;i++)
    {
        if(a[i]<=sum)
        {
            //sum -=a[i];
            cout<<a[i]<<" ";
            coin_check(a, size, sum-a[i], i);
        }
    }
}
