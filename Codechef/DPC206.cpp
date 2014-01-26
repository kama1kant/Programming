#include<iostream>

using namespace std;

int palin(int n)
{
    int n2 , s=0, r;
    n2 = n;
    do {
           r=n2%10;
           s = s*10+r;
           n2 = n2/10;
       }while(n2>0);
    if(n==s)
        return 1;
    else
        return 0;
}

int main()
{
    int t, r, n1, n2;
    char *s1 = new char();
    char *s2 = new char();
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int count = 0;
        cin>>n1;
        n2 = n1;

        do{
            int s=0;
            count++;
            do {
                    r=n2%10;
                    s = s*10+r;
                    n2 = n2/10;
                }while(n2>0);

            n1 = s+n1;
            n2 = n1;
        }while(palin(n1)!=1);
        cout<<count<<" "<<n1<<"\n";
    }
    return 0;
}
