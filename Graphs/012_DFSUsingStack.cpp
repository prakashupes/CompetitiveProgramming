#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<stack>
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



    void dfs(T src)
    {
        map<T,bool> visited;//
       // map<T,T> parent;
        stack<T> s;
        s.push(src);
        visited[src]=true;

        while(!s.empty())
        {
            T node =s.top();
            s.pop();
            cout<<node<<" ";
            for(auto neigh: graph[node])
            {
                if(!visited[neigh])
                {
                    visited[neigh]=true;
                    s.push(neigh);

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
    g.insertEdge("modi","kim",false);
    g.insertEdge("putin","trump",false);
    g.insertEdge("trump","kim");

    g.traverse();

    cout<<"\nDFS:\n";
    g.dfs("modi");

}


