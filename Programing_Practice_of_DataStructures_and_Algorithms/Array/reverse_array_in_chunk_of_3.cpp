#include<iostream>

using namespace std;
void reverse(int a[], int n);

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverse(a, 10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

void reverse(int a[], int n)
{
    int i=0, temp;
    while(i<n)
    {
        if(i+2 < n)
        {
            temp = a[i+2];
            a[i+2] = a[i];
            a[i] = temp;
            i = i+3;
        }
        else
            break;
    }
}
