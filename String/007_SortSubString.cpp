#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
int n;
cin>>n;
vector<string> v;
string s;int a,b;
while(n>0){
cin>>s>>a>>b;
sort(s.begin()+a,s.begin()+a+b,greater<char>());
v.push_back(s);
n--;
}
for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
}
