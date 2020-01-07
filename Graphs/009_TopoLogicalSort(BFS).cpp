#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T,list<T>> adjList;
    public:

    void addEdge(T u,T v,bool bidir=false)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }

    }

    void bfsTopological()
    {
        //map<T,bool>visited;
        map<T,int> inorder;
        queue<T>q;

        //Initialize all inoreder 0
        for(auto x:adjList)
        {
            T node=x.first;

                inorder[node]=0;
                //visited[node]=false;

        }

        //Add inorder for each nodes

        for(auto x:adjList)
        {
            T node=x.first;
            for(auto n:adjList[node])
            {
                inorder[n]++;
            }
        }

        //insert nodes into queue with inorder of 0

        for(auto x:adjList)
        {
            T node=x.first;
            if(inorder[node]==0)
            {
                q.push(node);
            }

        }

        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            cout<<node<<" ";
            //Reduce degree of neighbour of poped node

            for(T x:adjList[node])
            {
                inorder[x]--;
                if(inorder[x]==0)
                {
                    q.push(x);
                }

            }

        }

    }

};

int main()
{
    Graph <int> g;
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(4,3);
    g.addEdge(7,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.bfsTopological();

}
