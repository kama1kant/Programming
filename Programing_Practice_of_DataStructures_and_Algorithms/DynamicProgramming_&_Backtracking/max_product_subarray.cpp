#include<iostream>

using namespace std;
int max_product(int a[], int n);

int main()
{
    int a[] = {-2, -3, 0, -2, -40};
    cout<<max_product(a, 5);
    return 0;
}

int max_product(int a[], int n)
{
    int max_ending = 1, min_ending = 1, max_total = 1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            max_ending = max_ending*a[i];
            min_ending = min(min_ending*a[i], 1);
        }
        else if(a[i] == 0)
        {
            max_ending = 1;
            min_ending = 1;
        }
        else
        {
            int temp = max_ending;
            max_ending = max(min_ending*a[i], 1);
            min_ending = temp*a[i];
        }
        if(max_total < max_ending)
            max_total = max_ending;
    }
    return max_total;
}
