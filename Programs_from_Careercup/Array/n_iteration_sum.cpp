#include<iostream>

using namespace std;

int n_iteration_sum(int a[], int n, int itr);

int main()
{
    int a[] = {4};
    cout<<n_iteration_sum(a, 1, 1);
    return 0;
}


int n_iteration_sum(int a[], int n, int itr)
{
	if(itr >= n)
		return -1;
    int j=0, sum =0;
	for(int i=0;i<itr;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			a[j] = a[j] - a[j+1];
		}
		a[j] = 0;
	}
	for(int i=0;i<n-itr;i++)
	{
		sum += a[i];
	}
	return sum;
}
