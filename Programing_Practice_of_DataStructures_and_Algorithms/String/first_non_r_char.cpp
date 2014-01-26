#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string>
#include<stack>
#define N 100

using namespace std;
char check(string s);

int main()
{
    string s;
    cin>>s;
    cout<<check(s);
    return 0;
}

char check(string s)
{
    int temp[256]={0};
    char c;
    for(int i=0;i<s.length();i++)
    {
        temp[s[i]]++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(temp[s[i]] == 1)
        {
            c = s[i];
            break;
        }
    }
    return c;
}
