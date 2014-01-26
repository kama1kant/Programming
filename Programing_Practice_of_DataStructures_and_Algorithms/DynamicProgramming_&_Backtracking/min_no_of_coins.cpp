#include<iostream>
#include<stdlib.h>
#include<climits>

using namespace std;
int find(int a[], int n, int sum, int *count, int tc);
int compare(const void*a, const void *b);

int main()
{
    int count = INT_MAX;
    int a[] = {5, 2, 5, 5, 5};
    qsort(a, 5, sizeof(a[0]), compare);
    find(a, 5, 2, &count, 0);
    if(count != INT_MAX)
        cout<<count;
    else
        cout<<-1;
    return 0;
}

int find(int a[], int n, int sum, int *count, int tc)
{
    if(sum == 0 && *count > tc)
        *count  = tc;
    for(int i=n-1;i>=0;i--)
    {
        if(sum-a[i] >= 0)
            find(a, n, sum-a[i], count, tc+1);
    }
}

int compare(const void*a, const void *b)
{
    if(*(int*)a > *(int*)b) return 1;
    if(*(int*)a == *(int*)b) return 0;
    if(*(int*)a < *(int*)b) return -1;
}
