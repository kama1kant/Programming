#include<iostream>

using namespace std;
int find_error(int n, int **matrix);

int main()
{
	int n, m, x, y;
	cin>>n>>m;
	int **matrix = new int*[n];
	for(int i=0;i<n;i++)
		matrix[i] = new int[n];
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		matrix[x-1][y-1] = 1;
	}
	x = find_error(n, matrix);
	cout<<x;
	return 0;
}

int find_error(int n, int **matrix)
{
	int count = 0, root = 0;
	for(int i=0;i<n;i++)
	{
		count = 0;
		for(int j=0;j<n;j++)
		{
			if(matrix[j][i] == 1)
			{
				count++;
			}
		}
		if(count > 1)
			return 1;
		if(count == 0)
			root++;
	}
	if(root == 0)
		return 1;
	if(root > 1)
		return 2;
	for(int i=0;i<n;i++)
	{
		count = 0;
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j] == 1)
				count++;
		}
		if(count > 2)
			return 3;
	}
	return 0;
}
