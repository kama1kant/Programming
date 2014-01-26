#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    char *s;
    int max = -1;
    int hash[256] = {0};
    //cin.getline(s, 256);
    for(int i=0;i<5;i++)
    {
        cout<<s[i];
        //hash[s[i]]++;
    }
    for(int i=0;i<256;i++)
    {
        if(max < hash[i])
        max = hash[i];
    }
    for(int i=65;i<=90;i++)
    {
        if(max == hash[i])
            printf("%c", hash[i]);
    }
    for(int i=97;i<=122;i++)
    {
        if(max == hash[i])
            printf("%c", hash[i]);
    }
    cout<<s;
    return 0;
}
