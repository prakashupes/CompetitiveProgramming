#include<iostream>
using namespace std;
typedef unsigned long int ul;
unsigned long int catalan(unsigned int n) 
{ 
    // Base case 
    if (n <= 1) 
        return 1; 
  
    // catalan(n) is sum of  
    // catalan(i)*catalan(n-i-1) 
    unsigned long int res = 0; 
    for (int i = 0; i < n; i++) 
        res += catalan(i)  
            * catalan(n - i - 1); 
  
    return res; 
}

ul catalanDp(int n,ul dp[])
{
	if(dp[n]!=-1) return dp[n];
	
	if(n==0 || n==1) return 1;
	
	ul res=0;
	
	for(int i=1;i<=n;i++)
	{
		res+=catalanDp(i-1,dp) * catalanDp(n-i,dp);
	
	}
	dp[n]=res;
	return dp[n];

}

int main()
{
	int n;
	cin>>n;
	ul dp[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=-1;
	}
	//cout<<catalan(n)<<endl;
	cout<<catalanDp(n,dp)<<endl;
	
	

}
