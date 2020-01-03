#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
bool compare(string a,string b)
{
string r = a.substr(0,b.length());
//transform(r.begin(),r.end(),r.begin(), ::tolower);
if(r==b)
{
return a>b;
}
r= b.substr(0,a.length());
//transform(r.begin(),r.end(),r.begin(), ::tolower);
if(r==a)
{
return b>a;
}
else
{
return a<b;
}
}
int main() {
	int n;
	cin>>n;
	string arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];

	}
	sort(arr,arr+n,compare);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;

	}
}
