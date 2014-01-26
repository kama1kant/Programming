#include<iostream>

using namespace std;
int path(int a[][4], int n);
int path_util(int a[][4], int n, int i , int j);
int issafe(int x);

int main()
{
	int a[4][4] = {1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1};
	int n = 4;
	cout<<path(a, n);
	return 0;
}

int path(int a[][4], int n)
{
	return path_util(a, n, 0, 0);
}

int path_util(int a[][4], int n, int i , int j)
{
	if(i == n-1 && j == n-1)
		return 1;
	if(issafe(a[i][j]))
	{
		return path_util(a, n, i+1, j) | path_util(a, n, i, j+1);

	}
	else
		return 0;
}

int issafe(int x)
{
	if(x == 1)
		return 1;
	else
		return 0;
}
