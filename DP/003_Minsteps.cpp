#include <iostream>
using namespace std;
#define max 10000
int memo[max];

int min(int a,int b)
{
	int min= a<b ? a: b;
	return min;
}

int minstep(int n)
{
	if(memo[n]!=-1) return memo[n];
	if(n==1) return 0;
	//if(n==max) return max;
	int x=max;
	int y=max;
	int z=max;
	if(n%3==0) x=minstep(n/3)+1;
	if(n%2==0) minstep(n/2)+1;
	z=minstep(n-1)+1;
	
	//return (min(minstep(x),min(minstep(y),minstep(z))))+1;
	memo[n]= min(x,min(y,z));
	return memo[n];
	

}
int main()
{	
	int n=1000;
	for(int i=0;i<=n;i++)
	{
		memo[i]=-1;
		
	}
	cout<<minstep(n);
	

}
