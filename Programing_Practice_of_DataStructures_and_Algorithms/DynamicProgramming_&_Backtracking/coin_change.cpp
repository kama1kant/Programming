#include<iostream>

using namespace std;
int coins(int sum);

int main()
{
    int sum;
    cin>>sum;
    cout<<coins(sum);
    return 0;
}

int coins(int sum)
{
    int x, y;
    int c[] = {1, 5, 10, 25, 50, 100};
    int **table = new int*[sum+1];
    for(int i=0;i<sum+1;i++)
    {
        table[i] = new int[6];
    }
    for(int i=0;i<sum+1;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(i == 0)
                table[i][j] = 1;
            else
                table[i][j] = 0;
        }
    }
    for(int i=1;i<sum+1;i++)
    {
        for(int j=0;j<6;j++)
        {
            x = (i-c[j] >= 0)?table[i-c[j]][j]:0;
            y = (j>0)?table[i][j-1]:0;
            table[i][j] = x+y;
        }
    }
    return table[sum][5];
}
