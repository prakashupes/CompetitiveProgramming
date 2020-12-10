#include<iostream>
#include <set> 
using namespace std;
int solun_1(string str,int n)
{
	set<char>s;
	int length=0, ans=0;
	for(int i=0;i<n;i++)
	{
		
		for(int j=i;j<n;j++)
		{
			if(s.find(str[j])!=s.end())
			{
				
				//cout<<*(s.find(str[j]));
				 break;
			}
			else
			{
				//cout<<str[j]<<" ";
				s.insert(str[j]);
				length++;
				
			
			}
			
		}
		//cout<<endl;
		
		ans= ans>length ? ans: length ;
		s.clear();
		length=0;
	
	}
	return ans;
}
using namespace std;
int main()
{
	string str= "abcdeajhiof";
	int n=str.length();
	
	cout<<solun_1(str,n);

}
