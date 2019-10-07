#include<iostream>
using namespace std;
int td_ways(int n,int m,int memo[])
{
	if(n==0)
    return 1;
	if(n<0)
	return 0;
	if(memo[n]!=-1)
	return memo[n];
	else{
		memo[n]=(td_ways(n-1,m,memo)+td_ways(n-m,m,memo));
		return memo[n];
	}
}
/*long long tilling(long long n,long m)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    return tilling(n-1,m)+tilling(n-m,m);
}*/
int main()
{
    int t;
    int n,m;
    int i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>m;
        int memo[n+1];
        for(i=0;i<=n;i++)
        memo[i]=-1;
        cout<<td_ways(n,m,memo)<<endl;

    }

}
