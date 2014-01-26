#include<iostream>
#include<string>

using namespace std;
int password_check(int ex[], int n, int en[], int m);
int main()
{
    int n, m;
    cin>>n>>m;
    int *ex = new int[n];
    int *en = new int[m];
    for(int i=0;i<n;i++)
        cin>>ex[i];
    for(int i=0;i<m;i++)
        cin>>en[i];
    cout<<password_check(ex, n, en, m);
    return 0;
}

int password_check(int ex[], int n, int en[], int m)
{
    int temp[10] = {0};
    int flag = 0, j=0;
    for(int i=0;i<m;i++)
    {
        if(en[i] != ex[j])
        {
            if(flag == 0)
            {
                temp[en[i]] = 1;
                flag = 1;
            }
            else
            {
                if(temp[en[i]] != 1)
                {
                    return 0;
                }
            }
        }
        else
            j++;
    }
    return 1;
}
