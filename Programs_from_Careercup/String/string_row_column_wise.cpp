#include<iostream>
#include<string>

using namespace std;
void print(string s, int r);

int main()
{
	string s;
	int r;
	cin>>s;
	cin>>r;
	print(s, r);
	return 0;
}

void print(string s, int r)
{
	string output;
	int n = s.length();
	if(r<=0)
		return;
	for(int i=0;i<r;i++)
	{
		for(int j=i;j<n;j=j+r)
			output.push_back(s[j]);
	}
	cout<<output;
}
