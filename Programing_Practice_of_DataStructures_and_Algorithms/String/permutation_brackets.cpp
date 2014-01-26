#include<iostream>

using namespace std;
void print(int n);
void print_util(int n, char a[], int pos, int open, int close, int oc, int cc);
void print(char a[], int n);

int main()
{
    int n = 5;
    print(n);
    return 0;
}

void print(int n)
{
    char *a = new char[2*n];
    print_util(n, a, 0, 0, 0, 0, 0);
}

void print_util(int n, char a[], int pos, int open, int close, int oc, int cc)
{
    if(pos == 2*n)
        print(a, 2*n);
    else
    {
        if(open < n)
        {
            a[pos] = '{';
            print_util(n, a, pos+1, open+1, close, oc+1, cc);
        }
        if(close < n && oc > cc)
        {
            a[pos] = '}';
            print_util(n, a, pos+1, open, close+1, oc, cc+1);
        }
    }
}

void print(char a[], int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<endl;
}
