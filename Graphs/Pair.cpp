#include<iostream>
#include<utility>
#include<map>
#include<vector>
using namespace std;
int main()
{
    pair<string,int> p;
    p.first="Abc";
    p.second=1;
    p.first=to_string(55);
    p.second=23;
    string a="jkkd";
    int b=3;
    p=make_pair(a,b);
    cout<<p.first<<endl;
    map<int,int >m;
    m[1]=2;
    for(auto x:m)
    {
        cout<<x.first<<" "<<x.second;
    }
    for(auto x=m.begin();x!=m.end();x++)
    {
        cout<<x->first;
    }


    //Vector of pair
    cout<<"\nVector of pair"<<endl;
    vector<pair<string,int>> v;
    v.push_back(make_pair("k1",2));
    v.push_back(make_pair("k2",2));
    v.push_back(make_pair("k3",2));

    for(auto x:v)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    for(auto x=v.begin();x!=v.end();x++)
    {
        cout<<x->first<<" "<<x->second<<endl;
    }



}
