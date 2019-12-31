#include<iostream>
#include<list>

using namespace std;

class Graph
{
    public:
    int v;
    list <int>* l;

    Graph(int v)
    {
        this->v=v;
        l=new list<int>[v];
    }

    void addEdges(int u, int v,bool bidirectional=true)
    {
        l[u].push_back(v);
        if(bidirectional)
        {
            l[v].push_back(u);
        }

    }

    void traverse()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<" ->";
            for(auto x:l[i])
            {
                cout<<x<<" ";

            }
            cout<<"\n";
        }

    }

};
int main()
{
    Graph g(3); //Here assumed vertices 0,1,2
    g.addEdges(0,2);
    g.addEdges(0,1);
    g.addEdges(1,2,false);
    g.traverse();



}
