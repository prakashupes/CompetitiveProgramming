#include<iostream>
#include<string>
using namespace std;

void flip(string &str,int a,int b)
{
	
	for(int i=a;i<=b;i+=2)
	{
		if(str[i]=='0') str[i]='1';
		else str[i]='0';
		
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string str1,str2;
	cin>>str1>>str2;
	int i=0,j=str1.size()-1;
	int ans=0;
	
	while(i<=j)
	{
		while(str1[i]==str2[i] && i<str1.size())
		{	
			i++;
		}	
		while((str1[j]==str2[j] && j>=i)){			
			j--;					
		}
		if(((j-i+1)%2!=0))
		{			
			flip(str1,i,j);
			ans++;
			j=str1.size()-1;
		}
		else j--;
		
		
	}
	cout<<ans<<endl;
	}
	
	

}
