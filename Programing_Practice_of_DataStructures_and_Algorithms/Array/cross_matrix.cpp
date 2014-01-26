#include<iostream>
#include<climits>
using namespace std;

int cross_matrix(int a[][3], int n);


int main()
{
    int a[][3] = {1, 2, 1, 4, 1, 6, 1, 8, 1};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<cross_matrix(a, n);
    return 0;
}


int cross_matrix(int a[][3], int n)
{
	int elem = a[0][0];
	int flag = 1;
	for(int i=0;i<n;i++)
	{
		if(a[i][i] != elem || a[i][n-i-1] != elem)
		{
			flag =0;
			break;
		}
	}
	if(flag == 0)
		return 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i == j || j == n-i-1)
				continue;
			else
			{
				if(a[i][j] == elem)
				{
					flag = 0;
					break;
				}
			}
		}
		if(flag == 0)
			break;
	}
	if(flag == 0)
		return 0;
    else
        return 1;
}
