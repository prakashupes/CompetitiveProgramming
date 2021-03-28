#include<iostream>
#include<algorithm>
#define M 100
#define N 100
using namespace std;
//dp

int max(int a,int b) {return a>b?a:b;}

//LCS top down
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
            dp[m][n]=max(lcs(dp,s1,s2,m-1,n),lcs(dp,s1,s2,m,n-1)); //ax a
        }
        
    }

    return dp[m][n];
    

}

//LCS Bottom up
int lcs_2 (string s1, string s2, int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++) dp[i][0]=0;

    for(int i=0;i<=n;i++) dp[0][i]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;

            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}


//print the LCS
void lcs_print(int dp[][N],string s1, string s2, int m,int n) //4 3
{
   int i=m;
   int j=n;
   string str="";
   while(i>0&&j>0)
   {
       if(s1[i-1]==s2[j-1])
       {
           str+=s1[i-1];//<<endl;
           i--;
           j--;
       }
       else
       {
           if(dp[i-1][j]>=dp[i][j-1])
           {
               i--;
           }
            else if(dp[i-1][j]<dp[i][j-1])
           {
               j--;
           }
       }
   }
   reverse(str.begin(),str.end());
   cout<<str<<endl;
}


//Space optimized
void Space_opti(string s1,string s2)
{
    int n=s1.length();
    int m=s2.length();

    int dp[2][m+1];

    int index=1;
    for(int i=0;i<=n;i++)
    {

        index=(!index);
       
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[index][j]=0;
            }
            
            else if(s1[i-1]==s2[j-1])
            {
                dp[index][j]=dp[1-index][j-1]+1;

            }
            else
            {
                dp[index][j]=max(dp[index][j-1],dp[1-index][j]);
            }


        }
    }

    cout<<dp[index][m]<<endl;
}

int main()

{
    string s1="ABCXYWYZQRTY",s2="ACWXYWQTY";
    
    int dp[M][N]={-1};
   for(int i=0;i<=s1.length();i++)
   {
       for(int j=0;j<=s2.length();j++)
       {
           dp[i][j]=-1;
       }
   } 

    cout<<lcs(dp,s1,s2,s1.length(),s2.length())<<endl;
   // cout<<lcs_2(s1,s2,s1.length(),s2.length())<<endl;


   // lcs_print(dp,s1,s2,s1.length(),s2.length());
   Space_opti(s1,s2);



}