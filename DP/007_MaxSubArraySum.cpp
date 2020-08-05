#include <iostream>
using namespace std;
int max(int a,int b)
{
	int m =a>b?a:b;
	return m;
}

int maxSum(int arr[],int i, int n)
{
	//if(dp[y]!=-1) return dp[y];
	
	if(i>=n-1) return 0; //no bottels left
	
	int s1= arr[i]+maxSum(arr,i+1,n); //price of bottel int nth+1 year 
	int s2= arr[i+1]+maxSum(arr,i+2,n) ;
	return max (s1,s2);
	
	//return dp[y];

}
int main ()
{
	int arr []={-3,2,5,-1,3};
	int n=sizeof(arr)/sizeof(arr[0]); 
	
	//int dp[100]={-1}; why is not working??
	
	int dp[100];	
	for(int i=0;i<100;i++) dp[i]=-1;
	cout<<maxSum(arr,0,n);
	
} 
