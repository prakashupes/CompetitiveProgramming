
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

    bool dfsHelper(T src, map<T,bool> &visited,map<T,T> &parent)
    {
        visited[src]=true;
        //cout<<src<<" ";

        //visit all the neighbours

        for(auto neighbour: graph[src])
        {
            if(visited[neighbour]==true && parent[src]!=neighbour)
            {
                return true;
            }

            if(!visited[neighbour])
            {
                //visited[neighbour]=true;
                parent[neighbour]=src;
                if(dfsHelper(neighbour,visited,parent))
                    return true;
                else return false;
            }
        }
    }

    void cycle(T src)
    {
        map<T,bool> visited;//
        map<T,T> parent;
        if(dfsHelper(src,visited,parent))
        {
            cout<<"Detected\n";

        }
        else
        {
            cout<<"Not\n";
        }

    }



};
int main()
{
    Graph<int> g;
    g.insertEdge(0,1);
    g.insertEdge(0,3);
    g.insertEdge(1,2);
    //g.insertEdge(3,2);

    g.traverse();
    g.cycle(0);



}


