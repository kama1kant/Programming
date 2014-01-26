#include<iostream>

using namespace std;
int check(int x, int a[], int size);
void num_generate(int n, int a[], int size);

int main()
{
    int n, size;
    cin>>n;
    cin>>size;
    int *a = new int[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    num_generate(n, a, size);
    return 0;
}

void num_generate(int n, int a[], int size)
{
    for(int i=1;i<=n;i++)
    {
        if(check(i, a, size))
            cout<<i<<" ";
    }
}

int check(int x, int a[], int size)
{
    int hash[10] = {0};
    int flag = 0, m;
    for(int i=0;i<size;i++)
    {
        hash[a[i]] = 1;
    }
    while(x > 0)
    {
        m = x%10;
        x /= 10;
        if(hash[m] == 1)
            flag = 1;
    }
    if(flag == 1)
        return 1;
    else
        return 0;


}
