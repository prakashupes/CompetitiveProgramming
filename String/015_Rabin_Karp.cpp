#include<iostream>
#include<unordered_map>
#include <cmath> 
using namespace std;
int main()
{
	string text="abcbcabbabc";
	string pat="abc";
	
	//find initial hash of t and p
	int n=text.length();
	int m=pat.length();
	
	int t=0,p=0;
	int q=1e9+7; //prime num for modulo
	int d=5; //If text are number 0,1,2... then take d=10
	for(int i=0;i<m;i++)
	{
		p= (p*d + pat[i])%q; //
		
		t= (t*d + text[i])%q;
	}
	
	for(int i=0;i<=n-m;i++)
	{
	//hash same then only compare strings
		if(p==t)
		{
			int j=0;
			for(j=0;j<m;j++)
			{
				if(pat[j]!=text[i+j]) break;
			
			}
			if(j==m) cout<<i<<" ";
		
		}
		//cout<<p<<" "<<t<<endl;
		//Calculate next hash
		if(i<=n-m)
		{
		t= (t*d + text[i+m] - (text[i]*pow(d,m)))  ;//%q
		
		if(t<0) t=t+q;
		}
		
	
	}

}
