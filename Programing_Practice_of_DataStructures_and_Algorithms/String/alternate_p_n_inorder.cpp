#include<iostream>

using namespace std;
void alternate(int a[], int n);
void swap(int a[], int n, int j, int i);

int main()
{
    int a[] = {-1, -2, 9, 4, -6, 7, -8, 10};
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    alternate(a, 8);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}


void alternate(int a[], int n)
{
    int j=0, flag = 1;
    for(int i=j;i<n;i++)
    {
        if(flag == 1 && a[i] >= 0)
        {
            swap(a, n, j, i);
            flag = 0;
            j++;
            i=j-1;
        }
        else if(flag == 0 && a[i] < 0)
        {
            //cout<<"here"<<i<<" ";
            swap(a, n, j, i);
            flag = 1;
            j++;
            i=j-1;
        }
    }
}

void swap(int a[], int n, int j, int i)
{
    int temp = a[i];
    for(int x=i;x>j;x--)
    {
        a[i] = a[i-1];
    }
    a[j] = temp;
}
