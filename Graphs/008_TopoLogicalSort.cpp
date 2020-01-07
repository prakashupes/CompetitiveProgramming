//Not generic

#include<bits/stdc++.h>
using namespace std;

void dfsHelper(int src,unordered_map<int,list<int>> adjList, map<int,bool> &visited,list<int>&topoShort)
{
    visited[src]=true;
    for(int x:adjList[src])
    {
        if(!visited[x])
        {
            visited[x]=true;
            dfsHelper(x,adjList,visited,topoShort);


        }
    }
    topoShort.push_front(src);

}

void dfs(unordered_map<int,list<int>> adjList)
{
    map<int,bool> visited;
    list<int>topoShort;

    //Visit node one by one
    //adjList[0], represents first independent node
for(auto x:adjList)
    {
        int node=x.first;
        if(!visited[node])
        {   cout<<node<<" ";
            dfsHelper(node,adjList,visited,topoShort);
        }

    }

    cout<<endl;


   // topoShort.push_front(src);
    for(int x:topoShort)
    {
        cout<<x<<" ";
    }

}


int main()
{
    unordered_map<int,list<int>> adjList;
    adjList[1].push_back(4);
    adjList[1].push_back(2);
    adjList[2].push_back(3);
    adjList[3].push_back(5);
    adjList[4].push_back(3);
    adjList[4].push_back(5);
    adjList[5].push_back(6);
    adjList[7].push_back(4);
    dfs(adjList);



}
