#include<iostream>

using namespace std;
void permute(int n, int i, int j);
void permute_util(int n, int p, int q, int x, char a[]);

int main()
{
	int n;
	cin>>n;
	permute(n, 0, 1);
	return 0;
}

void permute(int n, int i, int j)
{
	char *a = new char[n];
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			a[i] = 'a';
			a[j] = 'a';
			permute_util(n, i, j, 0, a);
		}
	}
}

void permute_util(int n, int p, int q, int x, char a[])
{
	if(x == n)
	{
		for(int i=0;i<n;i++)
			cout<<a[i];
		cout<<" ";
		return;
	}
	for(int i=98;i<=122;i++)
	{
		if(x != p && x != q)
		{
			a[x] = i;
			i++;
			permute_util(n, p, q, x+1, a);
		}
		else
			x++;
	}
}
