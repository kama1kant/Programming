#include<iostream>
#include<string.h>
#include<malloc.h>

using namespace std;

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
    int k, flag=1;
    char ch;
    char *tk = new char[100];
    for(int j=0;j<t;j++)
    {
        char *s = new char[100];
        cin>>s;
        if(j==0)
        ch = s[0];

        if(j!=0 && ch != s[0])
        {
            cout<<"YES\n";
            flag = 0;
            break;
        }
            free(s);
    }
    if(flag==1)
        cout<<"NO\n";
}
return 0;
}
