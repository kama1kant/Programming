#include<iostream>
#include<climits>

using namespace std;
void k_largest_in_array(int a[], int n, int k);
int find_min(int a[], int n);

int main()
{   int a[] = {1, 23, 12, 9, 30, 2, 50};
    k_largest_in_array(a, 6, 3);
    return 0;
}

void k_largest_in_array(int a[], int n, int k)
{
	int *temp = new int[k];
	int min_index = 0;
	temp[0] = a[0];
	for(int i=1;i<k;i++)
	{
		temp[i] = a[i];
		if(temp[i] < a[min_index])
			min_index = i;
	}
	for(int i=k;i<n;i++)
	{
		if(a[i] > temp[min_index])
		{
			temp[min_index] = a[i];
			min_index = find_min(temp, k);
		}
	}
	cout<<"k largest elem : \n";
	for(int i=0;i<k;i++)
	{
		cout<<temp[i]<<" ";
	}
}

int find_min(int a[], int n)
{
	int min = 0;
	for(int i=1;i<n;i++)
	{
		if(a[i] < a[min])
			min = i;
	}
	return min;
}
