#include<iostream>
#include<climits>
#include<deque>

using namespace std;

int min_in_k(int a[], int n, int k);

int main()
{
    int a[] = {2, 7, 4, 1, 3, 9, 12};
    int n = sizeof(a)/sizeof(a[0]);
    int *b;
    int k=3;
    min_in_k(a, n, k);
    //b = min_in_k(a, n, k);
    /*for(int i=0;i<n-k+1;i++)
        cout<<b[i];
    */
    return 0;
}



int min_in_k(int a[], int n, int k)
{
	deque<int> mydeque;
	//int *b = new int[n-k+1];
	int j=0;
	for(int i=0;i<k;i++)
	{
		while(!mydeque.empty() && a[i] <= a[mydeque.back()])
			mydeque.pop_back();
		mydeque.push_back(i);
	}
	for(int i=k;i<n;i++)
	{
		cout<<a[mydeque.front()];
		//b[j] = a[mydeque.front()];
		j++;
		while((!mydeque.empty()) && mydeque.front() <= i-k)
		{
		    cout<<"pop front = "<<mydeque.front()<<endl;
		    mydeque.pop_front();
		}

		while((!mydeque.empty()) && a[i] <= a[mydeque.back()]);
		{
   		    cout<<"pop back = "<<mydeque.back()<<endl;
		    mydeque.pop_back();
		}
	    cout<<"push back = "<<mydeque.back()<<endl;
		mydeque.push_back(i);
	}
	cout<<a[mydeque.front()];
	//b[j] = a[mydeque.front()];
	//return b;
}
