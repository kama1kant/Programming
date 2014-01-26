#include<iostream>

using namespace std;
int check(int a[] , int n);

int main()
{
	int a[] = {0, 1, 2, 2, 4};
	cout<<check(a, 5);
	return 0;
}

int check(int a[] , int n)
{
	int x = a[0];
	for(int i=1;i<n;i++)
		x ^= a[i];
	for(int i=0;i<n;i++)
		x ^= i;
	return (x != 0);
}
