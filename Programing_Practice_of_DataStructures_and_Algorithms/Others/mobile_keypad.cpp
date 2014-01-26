#include<iostream>
#include<map>

using namespace std;
void permutation(string input);
void permutation_util(string input, int n, map<char, string>m, int pos1, int pos2, char *output);
void show(char output[], int n);

int main()
{
	string input;
	cin>>input;
	permutation(input);
	return 0;
}

void permutation(string input)
{
	int n = input.length();
	char *output = new char[n];
	map<char, string>m;
	m['1'] = "abc";
	m['2'] = "def";
	m['3'] = "ghi";
	m['4'] = "jkl";
	m['5'] = "mno";
	m['6'] = "pqr";
	m['7'] = "stu";
	m['8'] = "vwx";
	m['9'] = "yz";
	permutation_util(input, n, m, 0, 0, output);
}

void permutation_util(string input, int n, map<char, string>m, int pos1, int pos2, char *output)
{
	if(pos2 == n)
	{
		show(output, n);
		return;
	}
	string s = m[input[pos1]];
	for(int i=0;i<s.length();i++)
	{
		output[pos2] = s[i];
		permutation_util(input, n, m, pos1+1, pos2+1, output);
	}
}

void show(char output[], int n)
{
	for(int i=0;i<n;i++)
		cout<<output[i];
	cout<<endl;
}
