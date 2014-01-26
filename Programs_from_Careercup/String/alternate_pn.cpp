#include<iostream>

using namespace std;

void alternate_pn(int a[], int n);
int push_aside(int a[], int n);
void swap(int *x, int *y);

int main()
{
    int a[] = {-1, -2, 4, 3, 5, -6, -7};
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    alternate_pn(a, 7);
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void alternate_pn(int a[], int n)
{
	int x = push_aside(a, n);
	if(x == -1)
		return;
	int j = x;
	for(int i=1;i<=n;i=i+2)
	{
		swap(&a[i], &a[j]);
		j++;
	}
}

int push_aside(int a[], int n)
{
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i] > 0)
		{
			swap(&a[i], &a[j]);
			j++;
		}
	}
	if(j == n || j == 0)
		return -1;
	return j;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
