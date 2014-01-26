#include<iostream>
#include<string>
#include<stack>

using namespace std;
void fts(float x);

int main()
{
    fts(763.4f);
    return 0;
}

void fts(float x)
{
    string s;
    stack<string> stk;
    int a = (int)x;
    int at = a;
    while(at>0)
    {
        stk.push(((at%10)-'0')+"");
        at /= 10;
    }
    while(!stk.empty())
    {
        s += stk.top();
        stk.pop();
    }
    float temp = (float)x-a;
    cout<<a<<" "<<temp<<endl;
    cout<<s;
}
