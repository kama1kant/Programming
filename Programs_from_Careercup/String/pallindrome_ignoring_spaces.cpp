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
    char x, y;
    int count = 0, max_count = 0;
    for(int i=1;i<s.length();i++)
    {
        x = i-1;
        y = i;
        count = 0;
        if(x > 0 && s[x] == ' ')
        {
            x--;
        }
        if(y < s.length()-1 && s[y] == ' ')
        {
            y++;
        }
        while(x>=0 && y<=s.length()-1 && s[x] == s[y])
        {
            x--;
            y++;
            count++;
            if(s[x] == ' ')
            {
                x--;
                continue;
            }
            if(s[y] == ' ')
            {
                y++;
                continue;
            }
        }
        if(count > max_count)
            max_count = count*2;
    }
    for(int i=1;i<s.length()-1;i++)
    {
        if(s[i] == ' ')
            continue;
        x = i-1;
        y = i+1;
        count = 0;
        if(s[x] == ' ')
        {
            x--;
            continue;
        }
        if(s[y] == ' ')
        {
            y++;
            continue;
        }

        while(x>=0 && y<=s.length()-1 && s[x] == s[y])
        {
            x--;
            y++;
            count++;
            if(s[x] == ' ')
            {
                x--;
                continue;
            }
            if(s[y] == ' ')
            {
                y++;
                continue;
            }
        }
        if(count > max_count)
            max_count = (count*2)+1;
    }
    return max_count;
}
