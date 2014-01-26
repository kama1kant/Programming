#include<iostream>
#include<string>

using namespace std;
string move(string s);

int main()
{
    string s = "abcde";
    string x = move(s);
    cout<<x;
    return 0;
}

string move(string s)
{
    int n = s.length();
    char temp = s[n-1];
    for(int i=n-1;i>=0;i--)
        s[i+1] = s[i];
    s[0] = temp;
    return s;
}
