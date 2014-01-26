#include<iostream>
#include<stdlib.h>
using namespace std;
void find_sum(int a[], int n, int sum);
void find_sum_util(int a[], int n, int sum, int temp[], int ti, int ai, int cur_sum);
void print(int a[], int n);
int comparator(const void *a, const void *b);

int main()
{
	int a[] = {10, 7, 5, 18, 12, 20, 15};
	find_sum(a, 7, 35);
	return 0;
}


void find_sum(int a[], int n, int sum)
{
	int *temp = new int[n];
	qsort(a, n, sizeof(int), &comparator);
	find_sum_util(a, n, sum, temp, 0, 0, 0);
}

void find_sum_util(int a[], int n, int sum, int temp[], int ti, int ai, int cur_sum)
{
	if(cur_sum > sum)
		return;
	else if(cur_sum == sum)
	{
		print(temp, ti);
	}
	else
	{
		for(int j=ai;j<n;j++)
		{
			if(cur_sum+a[j] <= sum)
			{
				temp[ti] = a[j];
				find_sum_util(a, n, sum, temp, ti+1, j+1, cur_sum+a[j]);
			}
			else
                break;
		}
	}
}

void print(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int comparator(const void *a, const void *b)
{
    if(*(int*)a < *(int*)b) return 1;
    else if(*(int*)a == *(int*)b) return 0;
    else return -1;
}
