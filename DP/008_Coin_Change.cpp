#include<iostream>
using namespace std;
//min coins reqired to change ??
// [1 7 10], total=15, ans:3 (7,7,1)
#define max 1000000;
int dp[10000]={-1};
int coinChange(int arr[],int n,int total)
{
    if(dp[total]!=-1) return dp[total];
    else
    {
        if(total==0) return 0;
        int res=max;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=total)
            {
                int ans=coinChange(arr,n,total-arr[i])+1;
                res= res<ans ? res:ans;
            }
        }
       dp[total] = res;
       return dp[total];
    }
    
    
}

//BOTTOM UP

int bottm_up(int arr[],int n,int total)
{
    int tbl[total+1];
    tbl[0]=0;

    for(int i=1;i<=total;i++)
    {
        int res=100000;

        for(int j=0;j<n;j++)
        {
            if(total>=arr[j])
            {
                int ans=1+tbl[total-arr[j]];

                res=res < ans ? res:ans;
                //cout<<res<<" "<<ans<<endl;

            }
        }
       
        tbl[i]=res;
    }
    return dp[total];
}
int min(int a,int b)
{
    return a<b ? a:b;
}
//pick and drop
int m2(int arr[],int n,int sum)
{
    if(sum==0) return 0;
    if(n==0) return 100000;

    int a1= m2(arr,n-1,sum);

    int a2=100000;
    if(sum>=arr[n-1])  a2=m2(arr,n-1,sum-arr[n-1])+1;

    return min(a1,a2);
}


int main()
{
    int arr[]={9, 6, 5, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int total=11;
    for(int i =0;i<=total;i++)dp[i]=-1;
    int w=0;
    cout<<coinChange(arr,n,total);
    cout<<endl;
    cout<<bottm_up(arr,n,total);
    cout<<endl;
   // cout<<m2(arr,n,total);
    
    
   
}