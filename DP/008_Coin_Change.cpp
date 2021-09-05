#include<iostream>
using namespace std;
//min coins reqired to change ??
// [1 7 10], sum=15, ans:3 (7,7,1)
#define max 1000000;
int coinChange(int arr[],int n,int sum)
{
    if(sum==0) return 0;
    int res=max;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=sum)
        {
            int ans=coinChange(arr,n,sum-arr[i])+1;
            res= res<ans ? res:ans;
        }
    }
    return res;
}

int main()
{
    int arr[]={9, 6, 5, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=11;
    int w=0;
    cout<<coinChange(arr,n,sum);
   
}