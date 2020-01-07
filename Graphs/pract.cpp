
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    unordered_map<T,list<T>> adjList;
    public:
    void addEdge(T node1, T node2, bool bidir=false)
    {
        adjList[node1].push_back(node2);
        if(bidir)
        {
            adjList[node2].push_back(node1);
        }

    }

    void bfsTopological()
    {
        //map<T,bool>visited;
        map<T,int> indegree;
        queue<T>q;

        //Initialize all inoreder 0
        for(auto x:adjList)
        {
            T node=x.first;

                indegree[node]=0;
                //visited[node]=false;
        }

        //Add indegree for each nodes

        for(auto x:adjList)
        {
            T node=x.first;
            for(auto n:adjList[node])
            {
                indegree[n]++;
            }
        }

        //insert nodes into queue with indegree of 0

        for(auto x:adjList)
        {
            T node=x.first;
            if(indegree[node]==0)
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
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }

            }

        }

    }

};

int main()
{
    Graph<int>g;
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(4,3);
    g.addEdge(7,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);
    //g.bfsTopological();

}
