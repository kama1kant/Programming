#include<iostream>

using namespace std;
void find(int a[], int size, int x);
void find_util(int a[], int size, int x, int p, int n, int d, int q, int h, int sum, int ii);

int main()
{
    int a[] = {1, 5, 10, 25, 50};
    find(a, 5, 100);
    return 0;
}

void find(int a[], int size, int x)
{
    find_util(a, size, x, 0, 0, 0, 0, 0, 0, 0);
}

void find_util(int a[], int size, int x, int p, int n, int d, int q, int h, int sum, int ii)
{
    if(sum > x)
        return;
    if(sum == x)
    {
        cout<<"penny = "<<p<<"\nnickel = "<<n<<"\ndime = "<<d<<"\nquarter = "<<q<<"\nhalf cent = "<<h<<endl<<endl;
        return;
    }
    for(int i=ii;i<size;i++)
    {
        if(sum+a[i] <= x)
        {
            //cout<<"here -- sum = "<<sum<<" a[i] = "<<a[i]<<" i = "<<i<<endl;
            if(a[i] == 1)
                find_util(a, size, x, p+1, n, d, q, h, sum+a[i], i);
            else if(a[i] == 5)
                find_util(a, size, x, p, n+1, d, q, h, sum+a[i], i);
            else if(a[i] == 10)
                find_util(a, size, x, p, n, d+1, q, h, sum+a[i], i);
            else if(a[i] == 25)
                find_util(a, size, x, p, n, d, q+1, h, sum+a[i], i);
            else if(a[i] == 50)
                find_util(a, size, x, p, n, d, q, h+1, sum+a[i], i);
        }
        else
            break;
    }
}
