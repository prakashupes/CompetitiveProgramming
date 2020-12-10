#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string str="abcbaabcbcab";
	string p="abc";
	
	int m=p.length();
	int n=str.length();
	
	for(int i=0;i<=(n-m);i++)
	{
		int j=0;
		for(j=0;j<m;j++)
		{
			if(p[j]!=str[i+j])
			{
				//cout<<p[j]<<" "<<str[i+j]<<endl;
				break;
			
			}
		
		}
		if(j==m)cout<<i<<" ";
	
	}
	cout<<endl;
	
	
	

}
