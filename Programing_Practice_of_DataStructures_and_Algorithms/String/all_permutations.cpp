#include<iostream>
#include<string.h>

using namespace std;

void all_permutations(char s[], int n, int i);
void swap(int &x, int &y);

int main()
{
    char s[] = "ABC";
    all_permutations(s, strlen(s), 0);
    return 0;
}

void all_permutations(char s[], int n, int i)
{
	if(i == n)
		cout<<s<<endl;
	for(int j=i;j<n;j++)
	{
		swap(s[i], s[j]);
		all_permutations(s, n, i+1);
		swap(s[i], s[j]);
	}
}


void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
