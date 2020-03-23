#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<map>
using namespace std;
template <typename T>
class Graph
{

    unordered_map<T,list<T>> graph;
    public:
    void insertEdge(T node1, T node2, bool bidir=true)
    {
        graph[node1].push_back(node2);
        if(bidir)
        {
            graph[node2].push_back(node1);
        }

    }

    void traverse()
    {
        for(auto x:graph)
        {
            cout<<x.first<<"->";
            for(auto d:x.second)
            {
                cout<<d<<" ";
            }
            cout<<"\n";
        }
    }

    bool cycle(T src)
    {
        queue<T> q;
        map<T,bool> visited;
        map<T,T> parent;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T node=q.front();
            //cout<<node<<" ";
            q.pop();
            for(auto x: graph[node]) // graph[node] represents all the nieghbours of node, so first visit them
            {


                if(visited[x]==true && x!=parent[node])
                {
                    return true;
                }
                else if(!visited[x])
                {
                    visited[x]=true;
                    q.push(x);
                    parent[x]=node;
                }



            }


        }
        return false;

    }

};

int main()
{
    Graph<int> g;
    g.insertEdge(0,1);
    g.insertEdge(1,2);
    //g.insertEdge(1,2);
    g.insertEdge(3,2);

    g.traverse();
    if(g.cycle(0)==true)
    {
        cout<<"Detect\n";

    }
    else
    {
        cout<<"Not";
    }


}
