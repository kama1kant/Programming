#include<iostream>

using namespace std;
int binary_median(int a[], int b[], int n);
int median(int a[], int low, int high);


int main()
{
    int a[] = {1, 12, 15, 26, 38};
    int b[] = {2, 13, 17, 30, 45};
    cout<<binary_median(a, b, 5);
    return 0;
}

int binary_median(int a[], int b[], int n)
{
	int low1 = 0, low2 = 0, high1 = n-1, high2 = n-1, m1, m2;
	while(1)
	{
		m1 = median(a, low1, high1);
		m2 = median(a, low2, high2);
		if(low1 == high1)
		{
			return((a[low1]+b[low2])/2);
		}
		if(low1+1 == high1)
		{
			return ((max(a[low1], b[low2]) + min(a[high1], b[high2]))/2);
		}
		if(a[m1] == b[m2])
			return m1;
		if(a[m1] < b[m2])
		{
			low1 = m1;
			high2 = m2;
		}
		else
		{
			low2 = m2;
			high1 = m1;
		}
	}
}

int median(int a[], int low, int high)
{
	int mid = (low+high)/2;
	return mid;
}
