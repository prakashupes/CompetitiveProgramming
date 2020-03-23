
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



    void path(T src,T dest)
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
            if(node==dest)
            {
                break;
            }
            cout<<node<<"-> ";

            for(auto neigh: graph[node])
            {

                if(!visited[neigh])
                {
                    visited[neigh]=true;
                    s.push(neigh);

                }

            }


        }
        cout<<dest;


    }





};
int main()
{
    Graph<int> g;
    g.insertEdge(0,1);
    g.insertEdge(0,2);
    g.insertEdge(0,3);
    g.insertEdge(1,2);
    g.insertEdge(2,3);
    g.insertEdge(2,4);
    g.insertEdge(3,4);
    g.insertEdge(3,5);
    g.insertEdge(4,5);



    g.traverse();

    cout<<"\nOne path is 0->2:\n";
    g.path(0,2);


}


