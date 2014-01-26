#include<iostream>
#include<climits>
#include<stdlib.h>

using namespace std;

int min_dist_pair(int a[], int n);
void bubble_sort(int list[], int n);
int main()
{

    int a[] = {1, 6, 2, 7, 4, 9, 5};
    cout<<min_dist_pair(a, 7);
    return 0;
}

int min_dist_pair(int a[], int n)
{
	int min = INT_MAX, dif = 0;
	bubble_sort(a, n);
	for(int i=1;i<n;i++)
	{
		dif = a[i] - a[i-1];
		if(dif < min)
			min = dif;
	}
	return min;
}

void bubble_sort(int list[], int n)
{
	int c, d, t;

	for (c = 0 ; c < ( n - 1 ); c++)
	{
		for (d = 0 ; d < n - c - 1; d++)
		{
			if (list[d] > list[d+1])
			{
				/* Swapping */

				t         = list[d];
				list[d]   = list[d+1];
				list[d+1] = t;
			}
		}
	}
}
