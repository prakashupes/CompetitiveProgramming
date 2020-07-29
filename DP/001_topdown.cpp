#include<iostream>
using namespace std;

int memo[100];

int fibo(int n)
{
	if(memo[n]!=-1) return memo[n];
	if(n==0 || n==1) return n;
	memo[n]=fibo(n-1)+fibo(n-2);
	return memo[n];
}
int main()
{
	int n=5;
	for(int i=0;i<=n;i++) memo[i]=-1;
	
	cout<<fibo(n);
	//cout<<memo[1];

}
