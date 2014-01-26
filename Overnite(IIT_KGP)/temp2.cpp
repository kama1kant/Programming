#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;
int main()
{
    int n,k,i,q,x,y;
    scanf("%d %d",&n,&k);
    int srank[n],sage[n];
    for(i=0;i<n;i++)
    scanf("%d",&srank[i]);
    for(i=0;i<n;i++)
    scanf("%d",&sage[i]);
    scanf("%d",&q);
    while(q)
    {   int c=0;
       cin>>x>>y;
       if(abs(sage[x-1]-sage[y-1])>k)
       {cout<<"-1\n";break;}
       else
       {
       for(int j=0;j<n;j++)
       {
            if(sage[y-1]<sage[x-1])
            {
                if(sage[j]<=(sage[y-1]+k)&&sage[j]>=(sage[x-1]-k))
                c++;
            }
            else
            {
              if(sage[j]<=(sage[x-1]+k)&&sage[j]>=(sage[y-1]-k))
                c++;
            }
       }
       }
       cout<<c<<endl;
    }
return 0;
}
