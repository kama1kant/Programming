//10 min

#include<iostream>

using namespace std;
int max_sum_not_adjacent(int a[], int n);

int main()
{

    int a[5] = {3, 2, 7, 10};
    cout<<max_sum_not_adjacent(a, 4);
    return 0;
}


int max_sum_not_adjacent(int a[], int n)
{
	int excl = 0, incl = 0, incl_old = 0;
	for(int i=0;i<n;i++)
	{
		incl_old = incl;
		incl = excl+a[i];
		excl = max(excl, incl_old);
	}
	return max(excl, incl);
}
