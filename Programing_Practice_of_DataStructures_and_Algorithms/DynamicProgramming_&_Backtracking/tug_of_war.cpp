#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
void print(int a[], int n);
void find(int a[], int n);
void find_util(int a[], int n, int temp[], int pos, int count, int sum, int cur_sum, int *min, int ftemp[]);

int main()
{
	int a[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	find(a, 11);
	return 0;
}


void find(int a[], int n)
{
	int *temp = new int[n];
	int *ftemp = new int[n];
	int sum = 0, min = INT_MAX;
	for(int i=0;i<n;i++)
	{
	    temp[i] = 0;
	    ftemp[i] = 0;
	    sum += a[i];
	}
	//cout<<"sum/2 = "<<sum/2;
	find_util(a, n, temp, 0, 0, sum, 0, &min, ftemp);
	for(int i=0;i<n;i++)
    {
        if(ftemp[i] == 1)
            cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(ftemp[i] != 1)
            cout<<a[i]<<" ";
    }
    cout<<endl;
}

void find_util(int a[], int n, int temp[], int pos, int count, int sum, int cur_sum, int *min, int ftemp[])
{
    if(pos > n)
        return;
	if(count >= n/2)
	{
	    //print(temp, n);
	    if(fabs(sum/2 - cur_sum)  < *min)
        {
            *min = fabs(sum/2 - cur_sum);
            //cout<<"-- "<<*min<<endl;
            for(int i=0;i<n;i++)
            {
                ftemp[i] = temp[i];
            }
        }
		return;
	}
	else
	{
		temp[pos] = 1;
		cur_sum += a[pos];
		find_util(a, n, temp, pos+1, count+1, sum, cur_sum, min, ftemp);
		temp[pos] = 0;
		cur_sum -= a[pos];
		find_util(a, n, temp, pos+1, count, sum, cur_sum, min, ftemp);
	}
}

void print(int a[], int n)

{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
