#include<iostream>
#include<climits>
using namespace std;

int sum_after_n_iteration(int a[], int n, int k);


int main()
{
    int a[] = {4, 6, 8, 3, 6};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<sum_after_n_iteration(a, n, 4);
    return 0;
}

int sum_after_n_iteration(int a[], int n, int k)
{
        if(k >= n)
            return -1;
	int sum = 0;
	for(int i=0;i<k;i++)
	{
		for(int j=1;j<n-i;j++)
		{
			a[j-1] = a[j-1]-a[j];
		}
	}
	for(int i=0;i<n-k;i++)
	{
		sum += a[i];
	}
	return sum;
}
