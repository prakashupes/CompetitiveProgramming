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
void prims(Graph g,int v,int src)
{
    map<int,bool> visited;
    map<int, int> parent;
    map<int,int> weigth;

    //1.First make inf to all weight

    for(int i=0;i<v;i++)
    {
        weigth[i]=inf;
        visited[i]=false;
    }
    weigth[src]=0;
    parent[src]=-1;

    //Visit all vertices

    for(int i=0;i<v;i++)
    {
        int minWtVert=findMin(visited,weigth,v);
        visited[minWtVert]=true;

        //Update its all neighbours
        for(auto neigh:g.adjList[minWtVert])
        {
            if(!visited[neigh.first] && (weigth[neigh.first]>neigh.second))
            {

                weigth[neigh.first]=neigh.second;
                parent[neigh.first]=minWtVert;
            }
        }
    }

    for(int i=1;i<v;i++)
    {
        cout<<i<<"->"<<parent[i]<<" :"<<weigth[i]<<endl;

    }



}

int main()

{
    int v=3;
    Graph g(v);
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);

    prims(g,v,0);

}
