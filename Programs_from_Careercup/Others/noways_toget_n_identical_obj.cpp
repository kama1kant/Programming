#include<iostream>
#include<string>

using namespace std;
int c(int n);
void c_util(int n, int sum, int *count);

int main()
{
    int n;
    cin>>n;
    cout<<c(n);
    return 0;
}

int c(int n)
{
    int count = 0;
    c_util(n, 0, &count);
    return count;
}

void c_util(int n, int sum, int *count)
{
    if(sum > n)
        return;
    if(sum == n)
        *count = *count+1;
    for(int i=1;i<=3;i++)
    {
        c_util(n, sum+i, count);
    }
}
