
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<map>
#define INT_MAX 10000;
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

    void ShortestPath(T src)
    {
        queue<T> q;

        map<T,int>distance;
        map<T,T>parent;

        for(auto x: graph)
        {
            distance[x.first]=INT_MAX;//let infinte

        }
        distance[src]=0;
        parent[src]=src;

        q.push(src);

        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            int x=INT_MAX;
            for(auto x: graph[node])
            {
                if(distance[x]== 10000)
                {
                    distance[x]=distance[node]+1;
                    parent[x]=node;
                    q.push(x);
                }
            }
        }

        cout<<"Distance from src: \n";
        for(auto x: distance)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
};

int main()
{
    Graph <int> g;
    g.insertEdge(0,1);
    g.insertEdge(0,2);
    g.insertEdge(1,3);
    g.insertEdge(2,3);
    g.insertEdge(2,4);
    g.insertEdge(4,5);
    g.ShortestPath(0);



}
