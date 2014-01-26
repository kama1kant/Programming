#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string>
#include<stack>
#define N 100

using namespace std;
int bgame(string s);

int main()
{
    string s;
    cin>>s;
    cout<<bgame(s);
    return 0;
}

int bgame(string s)
{
    int a=0, p=1;
    for(int i=0;i<s.length();i++)
    {
        if(a < 0)
            break;
        if(s[i] == 'W')
        {
            a = a+p;
            p=1;
        }
        if(s[i] == 'L')
        {
            a = a-p;
            p = p*2;
        }
    }
    return a;
}
