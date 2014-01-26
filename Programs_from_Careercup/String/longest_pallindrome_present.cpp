#include<iostream>
#include<string>
#include<stack>

using namespace std;
int pal(string s);

int main()
{
    string s = "abcicbbcdefggfed";
    cout<<pal(s);
    return 0;
}


int pal(string s)
{
    int count = 0, start, end, max_count = 0, start_i_temp, start_i;
    for(int i=1;i<s.length()-1;i++)                 //odd length pallindrome
    {
        start = i;
        end = i;
        count = 0;
        start_i_temp = start;
        while(s[start] == s[end] && start>=0 && end <= s.length()-1)
        {
            start--;
            end++;
            count++;

        }
        start_i_temp = start+1;
        if(count > max_count)
        {
            max_count = count;
            start_i = start_i_temp;
        }
    }
    for(int i=1;i<s.length();i++)                   //even length pallindrome
    {
        start = i-1;
        end = i;
        start_i_temp = start;
        count = 0;
        while(s[start] == s[end] && start>=0 && end <= s.length()-1)
        {
            start--;
            end++;
            count++;
        }
        start_i_temp = start+1;
        if(count > max_count)
        {
            max_count = count;
            start_i = start_i_temp;
        }
    }
    cout<<"start = "<<start_i<<endl;
    for(int i=start_i;i<=(max_count*2)+start_i;i++)
        cout<<s[i];
    cout<<endl;
    return max_count*2;
}
