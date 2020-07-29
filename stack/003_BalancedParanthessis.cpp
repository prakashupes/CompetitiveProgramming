#include<iostream>
#include<stack>
using namespace std;

bool checkPair(char a, char b)
{
	if (a=='}' && b== '{') return true;
	if (a==']' && b== '[') return true;
	if (a==')' && b== '(') return true;
	return false;

}
bool balanced(string str)
{
	stack<char> s;
	for(int i=0;i<str.length();i++){	
		if(str[i]=='{' || str[i]=='[' || str[i]=='(') s.push(str[i]);
		
		else{
			if(s.empty()) return false;
			
			if(!checkPair(str[i],s.top())) return false;
			
			s.pop();	
		}
	}
	if(!s.empty()) return false;
	return true;
}
int main()
{
	string str="(()";
	if(balanced(str))cout<<"Yes";
	else cout <<"No";
	

}
