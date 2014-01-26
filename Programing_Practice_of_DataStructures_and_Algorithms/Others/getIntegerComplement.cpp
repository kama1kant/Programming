#include<iostream>
// 5:14
using namespace std;
int getIntegerComplement(int );

int main()
{
    int num = getIntegerComplement(100);
    cout<<num;
    return 0;
}

int getIntegerComplement(int n)
{
    int result = 0, one = 1, loc = 0;
    for(int i=0;i<32;i++)
    {
        if((n&one) !=0)
        {
            loc = i;
        }
        one = one<<1;
    }
    one = 1;
    for(int i=0;i<=loc;i++)
    {
        if((n&one) == 0)
        {
            result |= one;
        }
        one = one<<1;
    }
    return(result);
}
