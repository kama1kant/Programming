#include<iostream>
#include<string>
#include<climits>

using namespace std;
void modify(int a[], int n);

int main()
{
    int a[] = {2, 4, 6, 8};
    modify(a, 4);
    for(int i=0;i<4;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

void modify(int a[], int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        if(a[i]%2 == 0)
            i++;
        if(a[j]%2 != 0)
            j--;
        if(a[i]%2 != 0 && a[j]%2 == 0 && i<j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
}
