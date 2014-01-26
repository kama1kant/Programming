#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string>
#define N 100
using namespace std;

string compress(string s);
void express(string s);


int main()
{
    string s;
    cin>>s;
    //string t = compress(s);
    //for(int i=0;i<t.length() && t[i]!='\0';i++)
    //cout<<t[i];
    express(s);
    //cout<<s;
    return 0;
}


void express(string s)
{
    char c = s[0];
    for(int i=0;i<s.length();i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            for(int j=0;j<s[i]-'0'-1;j++)
            {
                cout<<c;
            }
        }
        else
        {
            c = s[i];
            cout<<c;
        }
    }
}

string compress(string s)
{
    char c = s[0];
    int count = 1, j=0;
    for(int i=1;i<s.length();i++)
    {
        if(c != s[i])
        {
            s[j] = c;
            j++;
            if(count != 1)
            {
                s[j] = count+'0';
                j++;
            }
            c = s[i];
            count = 1;
        }
        else
            count++;
    }

        s[j] = c;
        j++;
        if(count > 1)
        {
            s[j] = count+'0';
            j++;
        }
        s[j] = '\0';
/*    for(int i=0;i<j;i++)
    {
        cout<<s[i];
    }
*/
return s;
}
