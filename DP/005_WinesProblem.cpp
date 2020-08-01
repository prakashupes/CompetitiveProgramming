#include <iostream>
using namespace std;
int max(int a,int b)
{
	int m =a>b?a:b;
	return m;
}

int maxProfit(int price[],int dp[],int i,int j,int y)
{
	//if(dp[y]!=-1) return dp[y];
	
	if(i>j) return 0; //no bottels left
	
	int p1=price[i]*y +maxProfit(price,dp,i+1,j,y+1); //price of bottel int nth+1 year 
	int p2=price[j]*y + maxProfit(price,dp,i,j-1,y+1);
	return max (p1,p2);
	
	//return dp[y];

}
int main ()
{
	int price []={2,3,5,1,4};//Price of bottels
	int year=1;
	int j=sizeof(price)/sizeof(price[0])-1; //back pointer
	
	//int dp[100]={-1}; why is not working??
	
	int dp[100];
	
	for(int i=0;i<100;i++) dp[i]=-1;
	
	
	cout<<maxProfit(price,dp,0,j,year);
	
} 
