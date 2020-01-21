#include<bits/stdc++.h>
using namespace std;

#define inf 1e9
int main()
{
    map<int,list<int>> m;
    m[0].push_back(0);
    m[0].push_back(1);
    m[0].push_back(2);
    m[1].push_back(3);
    m[2].push_back(4);

    list<pair<int,int>> l[5];
    l[0].push_back(make_pair(1,2));


    for(auto x:m)
    {
        cout<<x.first<<"->";
        for(int value:m[x.first])
        {
            cout<<value<<" ";
        }
        cout<<endl;


    }
    cout<<inf;

}
