#include<iostream>

using namespace std;
int find_greatest(int a[], int n, int low, int high);
int find_rotation(int a[], int n);

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    cout<<find_rotation(a, 5);
    return 0;
}


int find_greatest(int a[], int n, int low, int high)
{
    if(a[low] < a[high])
        return -1;
    else if (a[high] < a[high-1])
        return n-1;
	while(low<high)
	{
		int mid = (low+high)/2;
		if(a[mid+1] < a[mid])
		{
			return mid;
		}
		else if(a[mid] > a[high])
			low = mid;
		else
			high = mid;
	}
	if(low == high)
		return low;
    if(low>high)
        return -1;
}

int find_rotation(int a[], int n)
{
	int low = 0, high = n-1;
	int x = find_greatest(a, n, low, high);
	if(x == high)
		return 0;
    else if(x == -1)
        return 0;
	else
		return (x+1);
}
