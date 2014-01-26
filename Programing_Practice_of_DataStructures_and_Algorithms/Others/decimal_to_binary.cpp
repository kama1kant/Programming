#include<iostream>
#include<string>
#include<climits>

using namespace std;
int dtbint(int n);
int dtb(float n);
int dtbfract(float n);

int main()
{
    float n = 10.6;
    cout<<n<<endl;
    dtb(n);
    return 0;
}


int dtb(float n)
{
    int in = (int)n;
    int t1 = dtbint(in);
    cout<<t1<<".";
    //cout<<"here - "<<n-in<<endl;
    if(n-in)
    {
        int t2 = dtbfract(n-in);
        cout<<t2<<endl;
    }
    else
        cout<<0<<endl;
}

int dtbint(int n)
{
    if(n == 0)
        return 0;
    int mod = n%2;
    int prev = dtbint(n/2);
    return ((prev*10)+mod);
}

int dtbfract(float n)
{
    int mod = 0, count = 0;
    while(n > 0)
    {
        n = n*2;
        mod = mod*10 + (int)n;
        n = n-mod;
        count++;
    }
    return mod;
}
