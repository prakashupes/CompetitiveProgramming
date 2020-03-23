#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class Graph
{

    unordered_map<T,list<T>> graph;// it is adjList
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

}
