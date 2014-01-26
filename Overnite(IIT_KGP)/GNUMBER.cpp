#include<iostream>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string n;
        cin>>n;
        string a = n;
        next_permutation(n.begin(),n.end());
        if(n<=a)
        cout<<"-1\n";
        else
        cout<<n<<"\n";
    }
    return 0;
}
