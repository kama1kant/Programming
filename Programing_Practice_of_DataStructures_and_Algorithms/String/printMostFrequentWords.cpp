#include<iostream>
#include<string>
#include<climits>

using namespace std;
void check(string s);

int main()
{
    string s;
    getline(cin, s);
    check(s);
    return 0;
}

void check(string s)
{
    char t[256] = {0};
    int max = INT_MIN;
    for(int i=0;i<s.length();i++)
    {
        t[s[i]]++;
    }
    for(int i=0;i<256;i++)
    {
        if(t[i] > max)
            max = t[i];
    }
    for(int i=0;i<s.length();i++)
    {
        if(t[s[i]] == max)
        {
            cout<<s[i];
            t[s[i]] = 0;
        }
    }
    cout<<" "<<max<<endl;
}
