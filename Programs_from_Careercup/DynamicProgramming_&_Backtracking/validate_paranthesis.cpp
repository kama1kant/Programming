#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string>
#include<stack>
#define N 100



using namespace std;

int validates(string s);
int main()
{
    string s;
    cin>>s;
    cout<<validates(s);
    return 0;
}

int validates(string s)
{
    stack<char> st;
    int flag = 1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(')
        {
            st.push('(');
        }
        if(s[i] == ')')
        {
            if(st.empty())
            {
                flag = 0;
                break;
            }
            st.pop();
        }
    }
    if(!st.empty())
    {
        flag = 0;
    }
    if(flag == 0)
        return 0;
    else
        return 1;
}
