#include<iostream>

using namespace std;
int find_occ(string txt, string pat);
string reverse(string s);
int kmp(string txt, string pat);
int create_lps(string pat, int m, int lps[]);

int main()
{
	string txt = "abcd";
	string pat = "dc";
	cout<<find_occ(txt, pat);
	return 0;
}

int find_occ(string txt, string pat)
{
	int count = 0;
	count += kmp(txt, pat);
	string x = reverse(pat);
    //cout<<x;
	count += kmp(txt, x);
	return count;
}

string reverse(string s)
{
	int i=0, j = s.length()-1;
	char temp;
	while(i<j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return s;
}

int kmp(string txt, string pat)
{
	int n = txt.length();
	int m = pat.length();
	int count = 0;
	int *lps = new int[m];
	create_lps(pat, m, lps);
	int i=0, j=0;
	while(i<n)
	{
		if(txt[i] == pat[j])
		{
			i++;
			j++;
		}
		if(j == m)
		{
			//cout<<i-j<<endl;
            count++;
			j = lps[j-1];
		}
		else if(txt[i] != pat[j])
		{
			if(j != 0)
			{
				j = pat[j-1];
			}
			else
				i++;
		}
	}
	return count;
}

int create_lps(string pat, int m, int lps[])
{
	int i=1, len = 0;
	lps[0] = 0;
	while(i<m)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
				len = lps[len-1];
			else
			{
				pat[i] = 0;
				i++;
			}
		}
	}
}
