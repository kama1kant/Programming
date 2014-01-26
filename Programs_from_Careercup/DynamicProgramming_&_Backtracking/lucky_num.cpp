#include<iostream>
#define min(a, b, c) (a<b?a<c?a:c:b<c?b:c)

using namespace std;
void lucky_num(int n);

int main()
{
	int n = 50;
	lucky_num(n);
	return 0;
}

void lucky_num(int n)
{
	int *a = new int[n];
	a[0] = 1;
	int i2=0, i3=0, i5=0, multiple_2 = 1, multiple_3 = 1, multiple_5 = 1, next_multiple;
	for(int i=1;i<n;i++)
	{

	         multiple_2 = a[i2]*2;
		 multiple_3 = a[i3]*3;
		 multiple_5 = a[i5]*5;
		next_multiple = min(multiple_2, multiple_3, multiple_5);
		a[i] = next_multiple;
        	if(next_multiple == multiple_2)
		{
			i2++;
		}
		if(next_multiple == multiple_3)
		{
			i3++;
		}
		if(next_multiple == multiple_5)
		{
			i5++;
		}

	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
