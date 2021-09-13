#include<iostream>
/*
coins[]={1,2,3}
sum=4
op: 4

*/
int memo[100][100];
using namespace std;
int recursicve(int arr[],int n,int sum)
{
    if(memo[sum][n]!=-1) return memo[sum][n];
    if(sum==0){ memo[sum][n]=1; return 1;}
    if(n==0) {memo[sum][n]=0; return 0;}

    int res=recursicve(arr,n-1,sum);

    if(sum>=arr[n-1])
    {
            res= res+ recursicve(arr,n,sum-arr[n-1]);
    }
    //cout<<res<<" ";
    memo[sum][n]=res;
    return res;
   

}

int main()
{
        int arr[]={1,2,3};
        int n=sizeof(arr)/sizeof(arr[0]);
        int sum=4;

        for(int i=0; i <=sum ;i++)
        {
                for(int j=0;j<=n;j++)
                {
                        memo[i][j]=-1;
                        //cout<<i<<" ";
                }
;        }
        //cout<<memo[sum][n];
        cout<<recursicve(arr,n,sum)<<endl;
}