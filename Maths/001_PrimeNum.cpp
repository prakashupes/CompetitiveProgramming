#include <iostream>
using namespace  std;

int isPrime(int n)
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
int main()
{
	int n;
	cout<<"Num: \n";
	cin>>n;
	if(isPrime(n)==1)
	{
		cout<<"Prime\n";
	}
	else
	{
		cout<<"Not prime!!\n";
	}

}

