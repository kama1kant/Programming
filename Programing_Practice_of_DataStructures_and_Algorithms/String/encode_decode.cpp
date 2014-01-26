#include<iostream>

using namespace std;

void encode_decode(char s[], int n);

int main()
{
    char s[] = "abc";
    encode_decode(s, 3);
    cout<<s;
    return 0;
}

void encode_decode(char s[], int n)
{
	int j=0, count = 1, elem = s[0];
	for(int i=1;i<n;i++)
	{

		if(s[i] != elem )
		{
			if(count > 1)
			{
				s[j] = elem;
				s[j+1] = count+'0';
			}
				elem = s[i];
                j += 2;
                count  = 1;
		}
		else
		{
			count++;
		}
	}
	if(count > 1)
	{
        s[j] = elem;
        s[j+1] = count+'0';
        if(j+2 <= n-1)
        s[j+2] = '\0';
	}

}
