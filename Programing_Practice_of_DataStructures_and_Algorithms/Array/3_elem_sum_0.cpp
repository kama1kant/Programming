#include<iostream>
#include<stdlib.h>

using namespace std;
void sum_of_three(int a[], int n);
int compare(const void *a, const void *b);

int main()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    sum_of_three(a, 6);
    return 0;
}

int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

void sum_of_three(int a[], int n)
{
	int j=0, k=0, sum=0;
	qsort(a, n, sizeof(int), compare);
	for(int i=0;i<n-2;i++)
	{
	    if(i != 0 && a[i] == a[i-1])
            continue;
		j=i+1;
		k = n-1;
		while(j<k)
		{
			sum = a[i]+a[j]+a[k];
			if(sum == 0)
			{
				cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
				j = j+1;
				k = k-1;
			}
			else if(sum < 0)
				j = j+1;
			else
				k = k-1;
		}
	}
}
