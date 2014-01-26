#include<iostream>
#define MAX 100

using namespace std;
int main()
{
int t, n, m, temp, count = 0, px[MAX], lx[MAX], py[MAX], ly[MAX];
cin>>t;

for(int i=0;i<t;i++)
{
    count = 0;
    cin>>n>>m;
    for(int j=0;j<n;j++)
    {
        cin>>temp;
        px[j] = temp;
        cin>>temp;
        lx[j] = temp;
    }

     for(int j=0;j<m;j++)
    {
        cin>>temp;
        py[j] = temp;
        cin>>temp;
        ly[j] = temp;
    }

    for(int j=0;j<m;j++)
    {
        for(int k=0;k<n;k++)
        {
            if(py[j] != 0)
            {
                if(ly[j] == lx[k])
                {
                    if(py[j] > px[k])
                    {
                        py[j] = py[j] - px[k];
                        px[k] = 0;
                    }

                    if(py[j] == px[k])
                    {
                        px[k] = 0;
                        py[j] = 0;
                    }

                    if(py[j] < px[k])
                    {
                        px[k] = px[k] - py[j];
                        py[j] = 0;
                    }
                }
            }
            else
            break;
        }
        count += py[j];
    }
    cout<<count<<endl;
}
return 0;
}
