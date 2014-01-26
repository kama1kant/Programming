#include<iostream>
#include<string>
#include<climits>

using namespace std;

int main()
{
    int hash[26] = {0};
    int max1 = INT_MIN, max2 = INT_MIN;
    string s = "aaaaaabbccccc";
    for(int i=0;i<s.length();i++)
    {
        hash[s[i]-97]++;
    }
    for(int i=0;i<26;i++)
    {
        if(hash[i] >= max1)
        {
            if(hash[i] != max1)
            max2 = max1;
            max1 = hash[i];
        }
        else if(hash[i] > max2)
        {
            max2 = hash[i];
        }
    }
    cout<<max2;
    return 0;
}


