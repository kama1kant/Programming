#include<iostream>

using namespace std;
void generate(char c[], int n, int i);
void all_combination_util(char c[], int n, char x[], int pos, int j);
void all_combination(char c[], int n);
void swap(char *x, char *y);

int main()
{
	char c[] = {'a', 'b', 'c', 'd'};
	all_combination(c, 4);
	return 0;
}

void all_combination(char c[], int n)
{
	for(int i=1;i<=n;i++)
	{
	    for(int j=0;j<n;j++)
        {
            //cout<<j<<" ";
       		char *x = new char[i];
            all_combination_util(c, i, x, 0, j);
        }
	}
}


void all_combination_util(char c[], int n, char x[], int pos, int j)
{
	if(pos == n)
	{
			for(int i=0;i<n;i++)
				cout<<x[i];
			cout<<endl;
		//generate(x, n, 0);
		return;
	}
	else
	{
		for(int i=j;i<n;i++)
		{
			x[pos] = c[i];
			all_combination_util(c, n, x, pos+1, i+1);
		}
	}
}

void generate(char c[], int n, int i)
{
	if(i == n)
	{
		for(int i=0;i<n;i++)
			cout<<c[i];
		cout<<endl;
	}
	else
	{
		for(int j=i;j<n;j++)
		{
			swap(&c[i], &c[j]);
			generate(c, n, i+1);
			swap(&c[i], &c[j]);
		}
	}
}

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
