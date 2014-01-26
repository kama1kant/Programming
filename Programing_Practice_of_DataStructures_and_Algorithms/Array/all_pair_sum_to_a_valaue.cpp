#include<iostream>

using namespace std;
void fun(int n);
void fun_util(int n, int a[], int j, int x, int sum);

int main()
{
	fun(5);
	return 0;
}

void fun(int n)
{
	int *a = new int[n];
	fun_util(n, a, 0, 1, 0);
}

void fun_util(int n, int a[], int j, int x, int sum)
{
	if(n == sum)
	{
		for(int i=0;i<j;i++)
			cout<<a[i];
		cout<<endl;
		return;
	}
	for(int i=x;i<n;i++)
	{
	    if(sum+i <= n)
		{
		    a[j] = i;
            fun_util(n, a, j+1, i, sum+i);
		}
	}
}
