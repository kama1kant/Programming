#include<iostream>
#define MAX 1000
using namespace std;

void mergeSort(int arr[],int low,int mid,int high)
{
    int i,m,k,l,temp[MAX];
    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }

    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}


void partition(int arr[],int low,int high)
{

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

//----------------------------------------


int main()
{
   int t,num,l,h,count=0;
   int i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>num>>l>>h;
        int a[1000];

        count = 0;
        for(int i=0;i<num;i++)
        {
            cin>>a[i];
        }
        partition(a, 0, num-1);
        for(i=0;i<num-2;i++)
        {
            for(j=i+1;j<num-1;j++)
            {
                for(k=j+1;k<num;k++)
                {
                    if(i<j && i<k && j<k)
                    {
                        int sum = a[i]+a[j]+a[k];
                        if(sum>=l && sum <=h)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}
