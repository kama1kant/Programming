#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string>
#include<stack>
#include<climits>

using namespace std;
int min_dif(int a[], int n);
int compare(const void *a, const void *b);

int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<min_dif(a, n);
    return 0;
}

int min_dif(int a[], int n)
{
    int min = INT_MAX;
    qsort(a, n, sizeof(int), compare);
    for(int i=1;i<n;i++)
    {
        if(a[i]-a[i-1] < min)
            min = a[i]-a[i-1];
    }
    return min;
}

int compare(const void *a, const void *b)
{
    if(*(int*)a < *(int*)b) return -1;
    if(*(int*)a == *(int*)b) return 0;
    if(*(int*)a > *(int*)b) return 1;
}
