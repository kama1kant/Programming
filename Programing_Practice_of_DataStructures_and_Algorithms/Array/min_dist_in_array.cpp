#include<iostream>
#include<cstdlib>

using namespace std;

int min_dist(int a[], int n, int x, int y);

int main()
{
    int a[] = {3, 4, 5, 7, 4, 8, 9};
    cout<<min_dist(a, 7, 4, 4);
    return 0;
}

int min_dist(int a[], int n, int x, int y)
{
	int p = -1, mind = 100, current_elem = -1, flag = 0;
	if(x == y)
		flag = 1;
	for(int i=0;i<n;i++)
	{
		if(current_elem == -1)
			current_elem = a[i];
		if(a[i] == x || a[i] == y)
		{
			if(a[i] != current_elem || flag == 1)
			{
				if(p != -1 && (abs(p-i) < mind))
					mind = abs(p-i);
				current_elem = a[i];
			}
				p = i;
		}
	}
	return mind;
}
