#include<iostream>
#include<deque>
using namespace std;
void min_of_karray(int a[], int n, int k);
int main()
{
    int a[] = {1, 4, 2, 6, 5, 9, 8, 7, 3};
    min_of_karray(a, 9, 3);
    return 0;
}


void min_of_karray(int a[], int n, int k)
{
	if(k>n)
		return;
	int m = n-k+1;
	int *b = new int [m];
	deque<int> mydq;
	mydq.push_back(0);
	int i=1, j=0;
	for(i=1;i<k;i++)
	{
		while(!mydq.empty() && a[i] <= a[mydq.back()])
		{
			mydq.pop_back();
		}
		mydq.push_back(i);
	}
	for(;i<n;i++)
	{
		b[j] = a[mydq.front()];
		j++;
		while(!mydq.empty() && mydq.front() <= i-k)
		{
			mydq.pop_front();
		}
		while(!mydq.empty() && a[i] <= a[mydq.back()])
		{
			mydq.pop_back();
		}
		mydq.push_back(i);
	}
	b[j] = a[mydq.front()];
	for(int x=0;x<m;x++)
	{
        cout<<b[x]<<" ";
	}
}
