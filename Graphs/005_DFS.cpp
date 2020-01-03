#include<iostream>
#include<map>

#include<unordered_map>
#include<list>
#include<queue>
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

    void dfsHelper(T src, map<T,bool> &visited)
    {
        visited[src]=true;
        cout<<src<<" ";

        //visit all the neighbours

        for(auto neighbour: graph[src])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour,visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T,bool> visited;
        dfsHelper(src,visited);

    }

        void BFS(T src)
    {
        queue<T> q;
        map<T,bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T node=q.front();
            cout<<node<<" ";
            q.pop();
            for(auto x: graph[node]) // graph[node] represents all the nieghbours of node, so first visit them
            {
                if(!visited[x])
                {
                    visited[x]=true;
                    q.push(x);
                }

            }


        }

    }

};
int main()
{
    Graph<string> g;
    g.insertEdge("modi","putin");
    g.insertEdge("modi","trump");
    g.insertEdge("modi","kim");
    g.insertEdge("putin","trump");
    g.insertEdge("trump","kim");
    cout<<"Graph is\n";
    g.traverse();
    cout<<"\nDFS is:(src=kim)\n";
    g.dfs("kim");

    cout<<"\nBFS is:"<<endl;
    g.BFS("kim");

}


