#include<iostream>
#include<string>

using namespace std;
int check(string s);

int main()
{
    string s;
    getline(cin, s);
    if(check(s) == 0)
        cout<<"False";
    else
        cout<<"True";
    return 0;
}


int check(string s)
{
    int i=0, j=s.length()-1;
    while(i<j)
    {
        if(s[i] == ' ')
        {
            i++;
            continue;
        }
        if(s[j] == ' ')
        {
            j--;
            continue;
        }
        if(s[i] != s[j])
            break;
        i++;
        j--;
    }
    if(i < j)
        return 0;
    return 1;
}
