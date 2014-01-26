#include<iostream>

using namespace std;
void merge_array(int a[], int b[], int m, int n);

int main()
{
    int a[8] = {7, 8, 9};
    int b[5] = {1, 2,  3, 4, 5};
    merge_array(a, b, 3, 5);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

void merge_array(int a[], int b[], int m, int n)
{
	for(int i=0;i<m;i++)
	{
		a[m+n-i-1] = a[m-i-1];
		a[m-i-1] = 0;
	}
	int i=0, j=n;
	for(int k=0;k<m+n-1;k++)
	{
		if(i == n)
			break;
		if(b[i] < a[j])
		{
			a[k] = b[i];
			i++;
		}
		else
		{
			a[k] = a[j];
			a[j] = 0;
			j++;
		}
	}
}
