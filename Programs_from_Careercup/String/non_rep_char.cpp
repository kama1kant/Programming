#include<iostream>

using namespace std;

int non_repeated(char input[], int n);

int main()
{
    char s[] = "abcabcdd";
    int n = sizeof(s)/sizeof(s[0]);
    int c = non_repeated(s, 8);
    if(c == -1)
    cout<<c;
    else
    cout<<(char)c;
    return 0;
}

int non_repeated(char input[], int n)
{
	int hash[256] = {0};
	for(int i=0;i<n;i++)
	{
		hash[input[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		if(hash[input[i]] == 1)
		{
			return input[i];
			//break;
		}
	}
	//cout<<"here";
	return -1;
}
