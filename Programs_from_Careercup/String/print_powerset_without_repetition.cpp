#include<iostream>

using namespace std;
void permutation(int a[], int n);

int main()
{
    int a[] = {1, 2, 2};
    permutation(a, 3);
    return 0;
}

void permutation(int a[], int n)
{
    int count, k;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            cout<<a[j];
            for(int k=j+1;k<=n-i-1;k++)
            {
                count=1;
                for(int x=k;count<i;x++)
                {
                    cout<<a[x];
                    count++;
                }
                cout<<endl;
            }
        }
    }
}
