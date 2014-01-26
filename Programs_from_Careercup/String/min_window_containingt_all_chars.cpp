#include<iostream>
#include<string>
#include<climits>

using namespace std;
void initialize(int temp[], string s, int n);
int isempty(int temp[]);
int find(string s1, string s2);

int main()
{
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    cout<<find(s1, s2);
    return 0;
}

int find(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    int temp[256] = {0};
    int len = 0, max_len = INT_MAX;
    for(int i=0;i<n1;i++)
    {
        initialize(temp, s2, n2);
        len = 0;
        if(temp[s1[i]] != 0)
        {
            for(int j=i;j<n1;j++)
            {
                if(temp[s1[j]] != 0)
                   temp[s1[j]]--;
                if(isempty(temp))
                {
                    len = j-i+1;
                    break;
                }
            }
            if(len != 0 && max_len > len)
                max_len = len;
        }
    }
    return max_len;
}

void initialize(int temp[], string s, int n)
{
    for(int i=0;i<256;i++)
    {
        temp[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        temp[s[i]]++;;
    }
}

int isempty(int temp[])
{
    int i;
    for(i=0;i<256;i++)
    {
        if(temp[i] != 0)
        {
            break;
        }
    }
    if(i == 256)
        return 1;
    else
        return 0;
}
