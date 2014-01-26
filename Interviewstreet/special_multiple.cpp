#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;
int find_multiple(int n);
int find_multiple_util(int n, int count, string s, int a09[2], int *ans);
int count_digits(int n);

int main()
{
    int t, n;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        cin>>n;
        cout<<find_multiple(n)<<endl;
    }
    return 0;
}

int find_multiple(int n)
{
    int count = count_digits(n);
    int x = 0;
    string s = "";
    int a09[2] = {0, 9};
    int ans = 0;
    while(ans == 0)
    {
        find_multiple_util(n, count, s, a09,&ans);
        x = ans;
        if(x)
        {
            return x;
            break;
        }
        else
            count++;
    }
    return ans;
}

int find_multiple_util(int n, int count, string s, int a09[2], int *ans)
{
    if(count == 0)
    {
        int num = atoi(s.c_str());
        if(num != 0 && num%n == 0)
        {
            *ans = num;
        }
        return *ans;
    }
    for(int i=0;i<2;i++)
    {
        char temp = a09[i]+'0';
        find_multiple_util(n, count-1, s+temp, a09, ans);
    }
}

int count_digits(int n)
{
    int count = 0;
    while(n)
    {
        count++;
        n = n/10;
    }
    return count;
}
