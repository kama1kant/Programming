#include<iostream>
#include<climits>
using namespace std;

int min_dist(int a[], int n, int x, int y);

int main()
{
    int a[] = {2, 7, 4, 2, 2, 9, 2};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<min_dist(a, n, 2, 2);
    return 0;
}

int min_dist(int a[], int n, int x, int y)
{
	int prev = 0, flag = 0, min_dist = INT_MAX, flag2 = 0;
	if(x == y)
		flag = 1;

	for(int i=0;i<n;i++)
	{
		if(a[i] == x || a[i] == y)
		{
			flag2++;
			prev = i;
			break;
		}
	}
	for(int i=prev+1;i<n;i++)
	{
		if(a[i] == x || a[i] == y)
		{
			if((flag == 1 || a[i] != prev) && (i-prev) < min_dist)
			{
				flag2++;
				min_dist = i-prev;
				prev = i;
			}
			else
				prev = i;
		}
	}
	if(flag2 <= 1)
		return -1;
	else
		return min_dist;
}
