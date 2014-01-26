#include<iostream>
#include<climits>

using namespace std;
int min_dist(int a[], int n, int x, int y);

int main()
{
    int a[] = {2, 6, 8, 43, 6, 8, 2, 0, 8};
    cout<<min_dist(a, 9, 2, 2);
    return 0;
}

int min_dist(int a[], int n, int x, int y)
{
    int t = -1, min = INT_MAX, flag = 0;
    if(x == y)
        flag = 1;
    for(int i=0;i<n;i++)
    {
        if(a[i] == x || a[i] == y)
        {
            if(t != -1 && (a[t] != a[i] || flag == 1))
            {
                //cout<<"here";
                if(i-t < min)
                {
                    min = i-t;
                }
            }
             t = i;
        }
    }
    return min;
}

