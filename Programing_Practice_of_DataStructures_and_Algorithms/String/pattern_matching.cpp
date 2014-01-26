#include<iostream>
#include<string>
#include<climits>

using namespace std;
int find(string txt, string pat);

int main()
{
	string txt = "ADBDDCDADBCD";
	string pat = "ACD";
	cout<<find(txt, pat);
	return 0;
}

int find(string txt, string pat)
{
	int j=0, start = 0, min_window = INT_MAX, m = pat.length(), n = txt.length();
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		if(j == 0 && txt[i] == pat[j])
		{
			start = i;
			while(j < m && i < n)
            {
                if(txt[i] == pat[j])
                    j++;
                i++;
            }
            if(j == m)
			{
				if(i-start < min_window)
					min_window = i-start;
			}
            j=0;
            i = start;
		}
	}
	return min_window;
}
