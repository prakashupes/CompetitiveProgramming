//Freq of charechters in string using unordered map
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int main()
{
    string str="ppptrpsts";
    unordered_map <char,int> m;
    for(int i=0;i<str.length();i++)
    {
        m[str[i]]++;

    }

    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->first<<" : "<<i->second<<endl;
    }

    cout<<"Remove duplicate of "<<str<<endl;
    unordered_set <char> s;
    for(int i=0;i<str.length();i++)
    {
        s.insert(str[i]);

    }
    for(char x:s)
    {
        cout<<x <<" ";
    }

}
