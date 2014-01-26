#include<iostream>
using namespace std;

int getpivoted(int a[], int n)
{
    int low = 0, high = n-1;
	while(low<high)
    {
        int mid = (low+high)/2;
        if(a[mid] > a[mid+1] && a[mid] > a[mid-1] && low>=0 && high<=n-1)
        {
            return mid;
        }
        if(a[mid]>a[0])
        {
            low = mid+1;
        }
        else if(a[mid]<a[0])
        {
            high = mid-1;
        }
    }
    return -1;
}


int search_element(int a[], int n, int search)
{
    int low = 0, high = n-1;
    int pivot = getpivoted(a, n);
    if(search >= a[0])
    {
        high = pivot;
    }
    else
    {
        low = pivot+1;
    }

	while(low <= high)
    {

        int mid = (low+high)/2;
        if(a[mid] == search )
        {
            return mid;
        }
        if(search>a[mid])
        {
            low = mid+1;
        }
        else if(search<a[mid])
        {
            high = mid-1;
        }
    }
    return -1;

}



int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int search = 0;
    cout<<"Enter element to search\n";
    cin>>search;
    int x = search_element(a, 10, search);
    if(x == -1)
        cout<<search<<" Not Found";
    else
        cout<<search<<" Found at index = "<<x;
    return 0;
}
