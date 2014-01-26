#include<iostream>
#include<algorithm>
#define MOD 1000000007

using namespace std;

int main()
{

    int t;
    unsigned long long int a, b, c, ans;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        if(a<=b && a<=c && b<=c)
        {
            ans = ((( (a%MOD)*((b-1)%MOD))%MOD )*((c-2)%MOD)%MOD);
            ans = ans%MOD;
        }
        else if(a<=b && a<=c && c<=b)
        {
            ans = ((( (a%MOD)*((c-1)%MOD))%MOD )*((b-2)%MOD)%MOD);
            ans = ans%MOD;
        }
        else if(b<=a && b<=c && c<=a)
        {
            ans = ((( (b%MOD)*((c-1)%MOD))%MOD )*((a-2)%MOD)%MOD);
            ans = ans%MOD;
        }
        else if(b<=a && b<=c && a<=c)
        {
            ans = ((( (b%MOD)*((a-1)%MOD))%MOD )*((c-2)%MOD)%MOD);
            ans = ans%MOD;
        }
        else if(c<=a && c<=b && a<=b)
        {
            ans = ((( (c%MOD)*((a-1)%MOD))%MOD )*((b-2)%MOD)%MOD);
            ans = ans%MOD;
        }
        else if(c<=a && c<=b && b<=a)
        {
            ans = ((( (c%MOD)*((b-1)%MOD))%MOD )*((a-2)%MOD)%MOD);
            ans = ans%MOD;
        }
        cout<<ans<<"\n";

    }
    return 0;
}
