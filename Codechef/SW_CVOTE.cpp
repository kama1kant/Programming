#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <map>
#include <cstring>

#define lint long long int
#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,a) for(i=0;i<a;i++)
#define frab(i, a, b) for(i=a;i<b;i++)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MOD 1000000007

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
}

struct classcomp {
    bool operator() (std::string lhs, std::string rhs) const
    {
      if(lhs == rhs) return false;
      return (lhs < rhs);
    }
};

using namespace std;
int main()
{
    INPUT_FROM_FILE();

    int N, M, i, j, max;
    char *ch1, *ch2, *ch;
    string maxStr;

    map<string, int, classcomp> chefToVotes, placeToVotes;
    map<string, int, classcomp>::iterator it;
    map<string, string, classcomp> chefToPlace;

    N = in();
    M = in();
    cin.ignore();

    fr(i, N)
    {
        ch1 = new char[11];
        ch2 = new char[11];

        cin.getline(ch1, 11, ' ');
        cin.getline(ch2, 11, '\n');

        chefToVotes[ch1] = 0;
        placeToVotes[ch2] = 0;
        chefToPlace[ch1] = ch2;
    }

    fr(i, M)
    {
        ch = new char[11];
        cin.getline(ch, 11, '\n');

        j = chefToVotes.at(ch);
        chefToVotes.erase(ch);
        chefToVotes[ch] = j+1;

        string s = chefToPlace.at(ch);
        j = placeToVotes.at(s);
        placeToVotes.erase(s);
        placeToVotes[s] = j+1;
    }

    max = (*placeToVotes.begin()).second;
    maxStr = (*placeToVotes.begin()).first;
    it = placeToVotes.begin();
    while(it != placeToVotes.end())
    {
        if((*it).second > max)
        {
            max = (*it).second;
            maxStr = (*it).first;
        }
        it++;
    }

    cout << maxStr << endl;

    max = (*chefToVotes.begin()).second;
    maxStr = (*chefToVotes.begin()).first;
    it = chefToVotes.begin();
    while(it != chefToVotes.end())
    {
        if((*it).second > max)
        {
            max = (*it).second;
            maxStr = (*it).first;
        }
        it++;
    }

    cout << maxStr << endl;

    return 0;
}
