#include<iostream>
#include<climits>
using namespace std;

void new_sorted_array(int a[], int n);
void swap(int *a, int *b);


int main()
{
    int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n = sizeof(a)/sizeof(a[0]);
    new_sorted_array(a, n);
    for(int i=0;i<n;i++)
        cout<<a[i];
    return 0;
}

void new_sorted_array(int a[], int n)
{
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i] != 0)
		{
			swap(&a[i], &a[j]);
			j++;
		}
	}
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
