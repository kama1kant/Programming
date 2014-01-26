#include<iostream>

using namespace std;
void find(int a[], int n, int sum);
void find_util(int a[], int n, int sum, int x[], int i, int cur_sum);
void print(int a[], int n);

int main()
{
    int a[] = {1, 2, 2, 3, 4, 5};
    find(a, 6, 5);
    return 0;
}

void find(int a[], int n, int sum)
{
    int *x = new int[n];
    find_util(a, n, sum, x, 0, 0);
}

void find_util(int a[], int n, int sum, int x[], int i, int cur_sum)
{
    if(cur_sum == sum)
    {
        print(x, i);
    }
    else
    {
        for(int j=i;j<n;j++)
        {
            //if(i == 0 && a[i] == a[i+1])
            //continue;
            if(cur_sum+a[j] <= sum)
            {
                x[i] = a[j];
                find_util(a, n, sum, x, i+1, cur_sum+a[j]);
            }
        }
    }
}

void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
}
