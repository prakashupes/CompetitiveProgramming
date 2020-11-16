#include <iostream>
#include <vector>
using namespace  std;

int IsPrime(int n)
{
	if(n==1 || n==2)
		return 1;
	for(int i=2;i*i<=n;i+=1)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}

void seive(vector<bool> &isPrime, int n)
{
	for(int i=2;i<=n;i++)
	{
	
		if(isPrime[i])
		{
			
			for(int j=i*i;j<=n;j+=i)
			{
				isPrime[j]=false;
			}
		}
		
	
	}

}
int main()
{
	int n;
	cout<<"Num: \n";
	cin>>n;
	vector<bool> isPrime (n+1,true);
	seive(isPrime,n);
	for(int i=2;i<=n;i++)
	{
		if(isPrime[i]) cout<<i<<endl;
	}

}

