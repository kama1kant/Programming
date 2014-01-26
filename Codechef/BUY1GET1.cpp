#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        int hash[52]={0}, index=0, sum=0;
        cin>>s;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]>='A' && s[j]<='Z')
            {
                index = (s[j]-'A')+26;
                hash[index] ++;
            }
            else if(s[j]>='a' && s[j]<='z')
            {
                index = (s[j]-'a');
                hash[index] ++;
            }
        }
        for(int j=0;j<52;j++)
        {
            if(hash[j]%2 == 0)
            sum += hash[j]/2;
            else
            sum += (hash[j]/2)+1;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
