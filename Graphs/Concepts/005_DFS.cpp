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
        map<T,bool> visited;//
       // map<T,T> parent;
        dfsHelper(src,visited);


    }



};
int main()
{
    Graph<string> g;
    g.insertEdge("modi","putin");
    g.insertEdge("modi","trump");
    g.insertEdge("modi","kim",false);
    g.insertEdge("putin","trump",false);
    g.insertEdge("trump","kim");

    g.traverse();

    cout<<"\nDFS:\n";
    g.dfs("modi");

}


