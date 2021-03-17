#include<iostream>
#define M 100
#define N 100
using namespace std;
//dp

int max(int a,int b) {return a>b?a:b;}
int lcs(int dp[][N],string s1, string s2, int m,int n) //4 3
{
    if(dp[m][n]!=-1) return dp[m][n];
    //base
    if(m == 0 || n == 0)
    {
        dp[m][n]=0;
    }

    else
    {
        if(s1[m-1]==s2[n-1])
        {
            dp[m][n] = 1+lcs(dp,s1,s2,m-1,n-1); 
        }
        else
        {
            dp[m][n]=max(lcs(dp,s1,s2,m-1,n),lcs(dp,s1,s2,m,n-1));
        }
        
    }

    return dp[m][n];
    

}
int main()
{
    string s1="ABC",s2="AC";
    
    int dp[M][N]={-1};
   for(int i=0;i<=s1.length();i++)
   {
       for(int j=0;j<=s2.length();j++)
       {
           dp[i][j]=-1;
       }
   } 

    cout<<lcs(dp,s1,s2,s1.length(),s2.length());

}