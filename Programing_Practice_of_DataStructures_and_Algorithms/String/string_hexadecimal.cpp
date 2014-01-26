#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
#include<math.h>

using namespace std;
void convert_string(char s[]);

int main()
{
    char s[] = "sita$0020and$123gita have books";
    for(int i=0;i<strlen(s);i++)
    {
        cout<<s[i];
    }
    cout<<endl;
    convert_string(s);
    return 0;
}


void convert_string(char s[])
{
	int len = strlen(s), flag = 0, j=0;
	stack<int> mystack;
	queue<char> myq;
	char *output = new char[len];
	for(int i=0;i<len;i++)
	{
		if(flag == 1)
		{
			if(s[i]-'0' >= 0 &&  s[i]-'0'<= 9)
			{
				mystack.push(s[i]-'0');
				myq.push(s[i]);
			}
			else
			{
				int sum = 0, power = 16, x = 0;
				while(!mystack.empty())
				{
					sum += mystack.top() * pow(power,x);
					mystack.pop();
					x++;
				}
				if(sum < 256)
				{
					output[j++] = sum;
					while(!myq.empty())
					{
					    myq.pop();
					}
				}
				else
				{
					output[j++] = '$';
					while(!myq.empty())
					{
						output[j++] = myq.front();
						myq.pop();
					}
				}
				output[j++] = s[i];
				flag = 0;
			}
		}
		else if(s[i] == '$')
		{
			flag = 1;
		}
		else
		{
			output[j++] = s[i];
		}
	}
	output[j] = '\0';
	for(int i=0;i<strlen(output);i++)
	{
		cout<<output[i];
	}
}
