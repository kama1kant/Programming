#include<iostream>
#include<string>

using namespace std;
int isomorphic(string s1, string s2);

int main()
{
    string s1 = "ab";
    string s2 = "ca";
    cout<<isomorphic(s1, s2);
    return 0;
}

int isomorphic(string s1, string s2)
{
    int temp[256];
    int n1 = s1.length(), n2 = s2.length();
    if(n1 != n2)
	return -1;
    for(int i=0;i<256;i++)
    {
        temp[i] = 0;
    }
    int i;
    for(i=0;i<n1;i++)
    {
        if(temp[s1[i]] == 0 && temp[s2[i]] == 0)
        {
            temp[s1[i]] = (int)s2[i];
            temp[s2[i]] = (int)s1[i];
        }
        if(temp[s1[i]] != (int)s2[i] || temp[s2[i]] != (int)s1[i])
            break;
    }
    if(i == n1)
        return 1;
    else
        return -1;
}
