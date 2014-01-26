#include <algorithm>
#include <string>
#include <iostream>

  using namespace std;
void permutation(string prefix, string str) {
    int n = str.length();
    if (n == 0) cout<<prefix<<endl;
    else {
        for (int i = 0; i < n; i++)
           permutation(prefix + str[i], str.substr(0, i) + str.substr(i+1, n));
    }
}

void permut(string str)
{
    permutation("", str);
}

int main()
{
    permut("abc");
    return 0;
}
