#include<iostream>
#include<stack>

using namespace std;
void fun(int a[], int n);

int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	fun(a, n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

void fun(int a[], int n)
{
	stack<int>s;
	s.push(0);
	for(int i=1;i<n;i++)
	{
		while(!s.empty() && a[i] > s.top())
		{
			a[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
	{
		s.pop();
	}

}
