#include<iostream>

using namespace std;

void alternate(int a[], int n);
int find(int a[], int j, int n, int flag);
int swap(int a[], int x, int j, int n);

int main()
{
    int a[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    alternate(a, n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}


void alternate(int a[], int n)
{
	int flag = 1, x, temp;
	if(n>0)
	{
		if(a[0] < 0)
			flag = 0;
		for(int i=1;i<n;i++)
		{
			if(flag == 1)
			{
				if(a[i] < 0)
				{
					flag = 0;
					continue;
				}
				x = find(a, i, n, flag);
				if(x == -1)
					break;
				temp = swap(a, x, i, n);
				a[i] = temp;
				flag = 0;
			}
			else
			{
				if(a[i] > 0)
				{
					flag = 1;
					continue;
				}
				x = find(a, i, n, flag);
				if(x == -1)
					break;
				temp = swap(a, x, i, n);
				a[i] = temp;
				flag = 1;
			}
		}
	}
}


int find(int a[], int j, int n, int flag)
{
	for(int i=j;i<n;i++)
	{
		if(flag == 1)
		{
			if(a[i] < 0)
				return i;
		}
		else
		{
			if(a[i] >= 0)
				return i;
		}
	}
	return -1;
}

int swap(int a[], int x, int j, int n)
{
	int temp = a[x];
	for(int i=x;i>j;i--)
	{
		a[i] = a[i-1];
	}
	return temp;
}
