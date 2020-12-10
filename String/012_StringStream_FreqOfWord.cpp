#include<iostream>
#include<unordered_map>
#include <sstream> 
using namespace std;
int main()
{
	string str="Hi this is this is p is";
	unordered_map<string, int> m;
	stringstream s(str);
	string word;
	while(s >> word) //Reading from string stream to str
	{
		m[word]++;
	
	}
	
	for(auto x:m)
	{
		cout<<x.first<<" "<<x.second<<endl;
	
	}
	
}
