#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s = "m";
    int i=0, j=s.length()-1;
    char temp;
    while(i<j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    cout<<s;
    return 0;
}

