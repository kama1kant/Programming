#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string>
#include<stack>
#define N 100

using namespace std;
int check(int a[], int n, int k);
int compare(const void *a, const void *b);

int main()
{
    int n, k;
    cin>>n;
    int a[N];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    cout<<check(a, n, k);
    return 0;
}

int check(int a[], int n, int k)
{
    int i=0, j=n-1, x, f=0;
    qsort(a, n, sizeof(int), compare);
    while(i<j)
    {
        x = a[i]+a[j];
        if(x == k)
        {
            f = 1;
            break;
        }
        else if(x < k)
        {
            i++;
        }
        else
            j--;
    }
    if(f == 1)
        return 1;
    else 0;
}

int compare(const void *a, const void *b)
{
    if(*(int*)a < *(int*)b) return -1;
    if(*(int*)a == *(int*)b) return 0;
    if(*(int*)a > *(int*)b) return 1;

}
