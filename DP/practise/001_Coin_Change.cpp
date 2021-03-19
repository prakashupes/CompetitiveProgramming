// A Naive recursive C++ program to find minimum of coins
// to make a given change V
#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;

// m is size of coins array (number of different coins)
int min(long long a,long long  b) 
{
  return a<b?a:b;
}
long long minCoins(long long coins[], long long n, long long size,long long dp[])
{
	if(n<0) return 0;
// base case
if(dp[n]!=-1) return dp[n];
if (n == 0) return 0;

// Initialize result
long long res = MAX;

// Try every coin that has smaller value than V
for (long long i=0; i<size; i++)
{
	if (coins[i] <= n)
	{
		long long sub_res =1+ minCoins(coins, n-coins[i], size,dp);
        res=min(res,sub_res);
	
	}
}
dp[n]=res;
return dp[n];
}

// Driver program to test above function

//M2


int main()
{
	long long coins[] = {1 , 5, 10, 20, 100};
	long long m = 5;//sizeof(coins)/sizeof(coins[0]);
	long long n ;
	cin>>n;
	long long dp[n+1];
    dp[0]=0;
	for(long long i=1;i<=n;i++)
        {
		dp[i]=-1;
	}
	
	//cout<<minCoins(coins, n ,m,dp);
    m2(n);
	return 0;
}
