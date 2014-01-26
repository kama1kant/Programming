#include<iostream>
#include<queue>

using namespace std;
int find_cost(int g, int ga[], int b, int r);

int main()
{
	int g, b, r;
	cin>>r>>b>>g;
	int *ga = new int[g];
	for(int i=0;i<g;i++)
	{
		cin>>ga[i];
	}
	cout<<find_cost(g, ga, b, r);
	return 0;
}

int find_cost(int g, int ga[], int b, int r)
{
	queue<int>q;
	int capacity = b, cost = 0;
	for(int i=0;i<g;i++)
		q.push(ga[i]);
	for(int i=0;i<r;i++)
	{
		capacity = b;
		while(!q.empty() && capacity-q.front() >= 0)
		{
			capacity -= q.front();
			cost += q.front();
			q.push(q.front());
			q.pop();
		}
	}
	return cost;
}
