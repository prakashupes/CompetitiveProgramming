#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

class Graph
{
     public:
    int v;
    list<pair<int,int>>* adjList; //Array of list
    //map<pair<int,int>>m //It(map) will give flexibilty

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
int findMin( map<int,bool> &visited, map<int,int> &weigth,int v)
{
    int minWtNode=-1;
    for(int i=0;i<v;i++) //I represents the nodes
    {
        if(!visited[i] && (minWtNode==-1 || weigth[i]<weigth[minWtNode]))
        {
            minWtNode=i;
        }

    }
    return minWtNode;

}
void prims(Graph g,int v)
{
    int start=2;
    map<int,bool> visited;
    map<int, int> parent;
    map<int,int> weigth;
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
        weigth[i]=inf;
    }
    parent[start]=-1;
    weigth[start]=0;
    for(int i=0;i<v;i++)
    {
        int minWtNode=findMin(visited,weigth,v);
        visited[minWtNode]=true;
        for(auto neigh: g.adjList[minWtNode])
        {
            if(!visited[neigh.first]) //negh.first represents destination, 0->1 1 is neigh.first
            {
                if(weigth[neigh.first]>neigh.second)
                {
                    weigth[neigh.first]=neigh.second;
                    parent[neigh.first]=minWtNode;
                } //neigh.second reprsnt wt fro adjList
            }
        }

    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<"->"<<parent[i]<<" :"<<weigth[i]<<endl;

    }



}

int main()

{
    /*int v=6;
    Graph g(v);
    g.addEdge(0,1,4);
    g.addEdge(0,2,5);
    g.addEdge(1,2,3);
    g.addEdge(1,3,7);
    g.addEdge(2,3,2);
    g.addEdge(1,4,9);
    g.addEdge(1,5,8);
    g.addEdge(4,5,11);
    prims(g,v);
    */
    int v=3;
    Graph g(v);
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(2,1,1);
    prims(g,v);

}
