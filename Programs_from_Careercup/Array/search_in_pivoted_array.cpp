#include<iostream>

using namespace std;
int search_pivot(int a[], int n);
int search_elem(int a[], int n, int x);
int binary_search(int a[], int low, int high, int x);

int main()
{
    int a[] = {2, 3, 4, 5, 1};
    cout<<search_elem(a, 5, 1);
    return 0;
}

int search_pivot(int a[], int n)
{
	int low = 0, high = n-1, mid;
	while(low<=high)
	{
		if(low == high)
			return low;
		mid = (low+high)/2;
		if(mid == 0 && a[mid] > a[mid+1])
            return mid;
		if(mid != 0 && a[mid] > a[mid-1] && a[mid] > a[mid+1])
		{
			return mid;
		}
		if(a[mid] < a[low])
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}

int search_elem(int a[], int n, int x)
{
	int loc;
	int pivot = search_pivot(a, n);
	if(pivot == -1)
		cout<<"Error";
	if(x < a[0])
		loc = binary_search(a, pivot+1, n-1, x);
	else
		loc = binary_search(a, 0, pivot, x);
	return loc;
}

int binary_search(int a[], int low, int high, int x)
{
    int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(a[mid] == x)
			return mid;
		if(a[mid] > x)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}












