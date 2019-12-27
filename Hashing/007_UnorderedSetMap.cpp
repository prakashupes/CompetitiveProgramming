#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;
int main()
{
    unordered_set <int> s;
    s.insert(12);
    s.insert(10);
    s.erase(10);
    cout<<*(s.begin())<<endl;

    for(auto x:s)
        cout<<x;

    unordered_map <string,int>m ;cout<<"\n\nMap:\n";

    m["k1"]=12;
    //m.insert("k2",55);
    m["k2"]=34;
    cout<<m["k1"];
    //cout<<*(m.begin()-);
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<"\n"<<i->first;

    }


}
