#include<iostream>
#include<string>
#include<stack>
#include<climits>

using namespace std;
int evaluate(string s);

int main()
{
    string s = "7+4*6";
    cout<<evaluate(s);
    return 0;
}

int evaluate(string s)
{
    stack<int> num;
    stack<char> plus;
    stack<char> mul;
    int a, b, x;
    for(int i=0;i<s.length();i++)
    {
        x = s[i]-'0';
        if(x >=0 && x <= 9)
        {
            num.push(x);
            if(!mul.empty())
            {
                a = num.top();
                num.pop();
                b = num.top();
                num.pop();
                num.push(a*b);
                mul.pop();
            }
        }
        else if(s[i] == '*')
        {
             mul.push(s[i]);
        }
        else if(s[i] == '+')
        {
            plus.push(s['+']);
        }
    }
    while(!plus.empty())
    {
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(a+b);
        plus.pop();
    }
    return num.top();
}
