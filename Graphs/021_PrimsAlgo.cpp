#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

class Graph
{
    int v;
    list<pair<int,int>>* adjList; //Array of list
    //map<pair<int,int>>m //It(map) will give flexibilty
    public:
    Graph(int v)
    {
        this->v=v;
        adjList=new list<pair<int,int>>[v]; //pair<des, wt>
    }
    void addEdge(int u,int v, int wt,bool bidir=true)
    {
        adjList[u].push_back(make_pair(v,wt));
        adjList[v].push_back(make_pair(u,wt));
    }


};
void prims(Graph g)
{
    map<int,bool> visited;
    map<int, int> parent;


}

int main()

{


}
