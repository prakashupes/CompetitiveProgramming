#include<iostream>
#include<unordered_map>
using namespace std;
void isPossible(string str)
{
    int diff,max_freq=0;
    unordered_map<char,int> m;
    for(int i=0;i<str.length();i++)
    {
        m[str[i]]++;

    }
    for(auto x:m)
    {
        if(x.second>max_freq)
            max_freq=x.second;
    }
    diff=str.length()-max_freq;
    cout<<max_freq;

    if(diff>=max_freq)
        cout<<"YES";
    else
        cout<<"No";

}
int main()
{
    string str="aabb";
    isPossible(str);



}
