#include<iostream>
#include<climits>

using namespace std;
int max_diff_betwn_2(int a[], int n);

int main()
{   int a[] = {7, 9, 5, 6, 3, 2};
    cout<<max_diff_betwn_2(a, 6);
    return 0;
}

int max_diff_betwn_2(int a[], int n)
{
	int min = a[0], max_diff = INT_MIN;
	for(int i=1;i<n;i++)
	{
		if(a[i] < min)
			min = a[i];
		else if(a[i] - min > max_diff)
			max_diff = a[i]-min;

	}
	return max_diff;
}
