#include<iostream>

using namespace std;

int main()
{
    int a = 17;
    int x=1;
    for(int i=0;i<32;i++)
    {
        if(a&x)
        {
            cout<<i+1<<" ";

        }
        x = x<<1;
    }
    return 0;
}

