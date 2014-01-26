#include<iostream>
#include<string>

using namespace std;
string ctou(string s);

int main()
{
    string s;
    cin>>s;
    cout<<ctou(s);
    return 0;
}

string ctou(string s)
{
    string t;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            if(i == 0)
                t.push_back(s[i]+32);
            else
            {
                t.push_back('_');
                t.push_back(s[i]+32);
            }
        }
        else
        {
            t.push_back(s[i]);
        }
    }
    return t;
}
