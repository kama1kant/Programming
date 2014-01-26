#include<iostream>

using namespace std;
int find(int a[], int n);

int main()
{
	int a[] = {0, 0, 1, 2, 2, 4, 4, 5, 5, 6, 6};
	cout<<find(a, 11);
	return 0;
}

int find(int a[], int n)
{
	int i=0, j=n-1, mid;
	while(i<=j)
	{
		mid = ((i+j)/2);
        if(mid%2 == 0)
            mid--;
		if(i == j)
			return i;
		if(a[mid] != a[mid-1] && a[mid] != a[mid+1])
			return mid;
		if(a[mid] != a[mid+1])
			i = mid+1;
		else
			j = mid-1;
	}
}
