#include<iostream>

using namespace std;

void flip_sort(int a[], int len);
void flip(int a[], int x);
int find_max(int a[], int len);

int main()
{
    int a[] = {4, 9, 1, 7, 6, 77, 5};
    flip_sort(a, 7);
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}


void flip_sort(int a[], int len)
{
    for(int i=len-1;i>=0;i--)
    {
        int x = find_max(a, i);
        flip(a, x);
        flip(a, i);
    }
}

void flip(int a[], int x)
{
    int low = 0, high = x;
    while(low<high)
    {
        int temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        low++;
        high--;
    }
}

int find_max(int a[], int len)
{
    int max = 0;
    for(int i=1;i<=len;i++)
    {
        if(a[max]<a[i])
        {
            max = i;
        }
    }
    return max;
}
