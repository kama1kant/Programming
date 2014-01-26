#include<iostream>
#include<string>

using namespace std;
string counter(string s);

int main()
{
    string s = "AB0CD101Z";
    cout<<counter(s);
    return 0;
}

string counter(string s)
{
    int carry = 0, x;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(x<10)
        {
            x = s[i]-'0';
            s[i] = ((x+1)%10)+'0';
            carry = (x+1)/10;
        }
        else
        {
            if(s[i] == 'Z')
            {
                carry = 1;
            }
            else
            {
                x = s[i]-'A';
                s[i] = ((x+1))+'A';
                carry = 0;
            }
        }
        if(carry == 0)
            break;
    }
    return s;
}
