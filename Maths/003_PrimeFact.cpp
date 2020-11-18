#include<iostream>
#include <vector>
using namespace std;

void fact(int n, vector<int> &facts)
{
	if(n==1) return ;
	
	while(n%2==0)
	{
		facts.push_back(2);
		n/=2;
	}
	while(n%3==0)
	{
		facts.push_back(3);
		n/=3;
	}
	for(int i=5;i*i<=n;i+=6)
	{
		while(n%i==0)
		{
		facts.push_back(i);
		n/=i;
		}
		while(n%(i+2)==0)
		{
		facts.push_back(i+2);
		n/=(i+2);
		}	
	
	}
	if(n>1) facts.push_back(n);
	

}

int main()
{
	int n; //176871 special num, 107, 176871

	cin>>n;
	vector<int> v;
	
	fact(n,v);
	
	for(auto x: v)
	{
		cout<<x<<" ";
	
	}
	cout<<endl;

}
