#include<iostream>
using namespace std;

int total(int *dp,int n)
{
	if(n==1)
	dp[n][0]=total(dp,n-1)+total(dp,n)
	
}
int main()
{
	int n=3;
	int arr[n][2];
	total(arr,n-1);
}
