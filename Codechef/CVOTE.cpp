#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main ()
{

    int n, m;
    string s;
    vector<string> chef;
    vector<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        chef.push_back(s);
    }
    for(int i=0;i<m;i++)
    {
        cin>>m;
        it = find (chef.begin(), chef.end(), m);

    }




  // iterator to vector element:
  ++it;
  cout << "The element following 30 is " << *it << endl;






    vector<string> myvectors;
    myvectors.push_back("ee");
    myvectors.push_back("ae");
    myvectors.push_back("a");
    myvectors.push_back("ab");
    vector<string>::iterator it;

    sort (myvectors.begin(), myvectors.end());

    cout << "vector contains:";
    for (int i = 0; i < myvectors.size(); ++i)
    cout << myvectors[i] << ' ';
    cout << endl;
  return 0;
}
