#include<iostream>
#include<climits>

using namespace std;

int min_coin(int a[], int n, int sum, int count, int temp_sum, int *tcount);


int main()
{
    int a[] = {1, 2, 3};
    int tcount = INT_MAX;
    min_coin(a, 3, 25, 0, 0, &tcount);
    cout<<tcount<<endl;
    return 0;
}


int min_coin(int a[], int n, int sum, int count, int temp_sum, int *tcount)
{
	if(temp_sum == sum)
    {
    	if(count < (*tcount))
		{
            (*tcount) = count;
            //cout<<count<<"--"<<endl;
		}

    }
    else
	{	for(int i=n-1;i>=0;i--)
		{
			if(temp_sum+a[i] <= sum)
			{
				count++;
				temp_sum += a[i];
				min_coin(a, n, sum, count, temp_sum, tcount);
			}
		}
	}
}
