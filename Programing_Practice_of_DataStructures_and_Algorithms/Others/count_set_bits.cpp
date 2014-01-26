#include<iostream>

using namespace std;
int set_bit_position(int num);

int main()
{
    int num = 19;
    cout<<set_bit_position(num);
    return 0;
}

int set_bit_position(int num)
{
	int x = num, count = 0;
	while(x != 0)
	{
		if(x & 1)
			count++;
		x = x>>1;
	}
	return count;
}
