#include<iostream>
#include<string>

using namespace std;
void n_to_s(int n, string *s);

int main()
{
    int n;
    cin>>n;
    string s;
    n_to_s(n, &s);
    cout<<s;
    return 0;
}

void n_to_s(int n, string *s)
{
    if(n == 26)
    {
        (*s).push_back('z');
    }
    else if(n < 26)
    {
        (*s).push_back((n%26)+96);
    }
    else
    {
        if(n%26 == 0)
        {
            n_to_s(n/26-1, s);
            (*s).push_back('z');
        }
        else
        {
            n_to_s(n/26, s);
            (*s).push_back((n%26)+96);
        }
    }
}
