#include<iostream>
#include<climits>

using namespace std;
int search_first_ocr(int a[], int n, int x);
int find_majority(int a[], int n, int x);

int main()
{   int a[] = {1, 1, 2, 4, 4, 4, 6, 6};
    cout<<find_majority(a, 8, 4);
    return 0;
}

int search_first_ocr(int a[], int n, int x)
{
	int low = 0, high = n-1, mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(a[mid] == x && (mid == 0 || a[mid-1] < x))
			return mid;
		if(a[mid] < x)
			low = mid+1;
		else
			high = mid-1;
	}
	return -1;
}

int find_majority(int a[], int n, int x)
{
	int pos = search_first_ocr(a, n, x);
	if(a[pos+(n/2)] == x)
		return 1;
	else
		return 0;
}
