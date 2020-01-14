#include<bits/stdc++.h>
using namespace std;
bool isBipertite(unordered_map<int,list<int>> adjList,int src)
{
    map<int,int>color;
    for(auto x:adjList)
    {
        color[x.first]=-1;
    }
    queue<int>q;
    q.push(src);
    color[src]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int x:adjList[node])
        {
            if(color[x]==-1)
            {
                color[x]=1-color[node];
                q.push(x);
            }

            if(color[x]==color[node])
            {
                return false;
            }
        }

    }
    return true;

}
int main()
{
    unordered_map<int,list<int>> g;
    g[1].push_back(2);g[2].push_back(1);
    g[1].push_back(4);g[4].push_back(1);
    g[2].push_back(3);g[3].push_back(2);
    g[3].push_back(4);g[4].push_back(3);
    if(isBipertite(g,1))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"NO";

    }
}
