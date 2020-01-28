#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

template <typename T>
class Graph
{
    unordered_map<T,list<pair<T,int>>> adjList; //pair<Destination,weight>
    public:
    void addEdge(T u,T v ,int wt,bool bidr=true)
    {
        adjList[u].push_back(make_pair(v,wt));
        if(bidr)
        {
            adjList[v].push_back(make_pair(u,wt));
        }

    }

    void printList()
    {
        for(auto x:adjList)
        {
            cout<<x.first<<"-> ";
            for(auto y : adjList[x.first])

            {
                cout<<"( "<<y.first<<", "<<y.second<<") ";

            }
            cout<<endl;

        }

    }

    void Dijikstra(T src)
    {
        unordered_map<T,int> distance;
        for(auto x: adjList)
        {
            distance[x.first]=INF;
        }

        //Set tofind out node with min distance

        set<pair<int,T>> s; //Sorting according tp distance
        distance[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            auto p=*(s.begin()); //Gives first pair of set, ie min wt/dist
            T node=p.second; //Node of pair

            int dis=p.first;
            s.erase(s.begin());

            for(auto child:adjList[node])
            {
                if(dis+child.second<distance[child.first])
                {
                    //In the set updation is not possible
                    //So, reove old pair and insert new pair
                    T destination =child.first;
                    auto f=s.find(make_pair(distance[destination],destination));
                    if(f!=s.end())
                    {
                        s.erase(f);

                    }
                    //Insert
                    distance[destination] =dis+child.second;
                    s.insert(make_pair(distance[destination],destination));

                }
            }


        }
        //Lests print dest to all other node node from source
        for(auto d: distance)
        {
            cout<<d.first<<" is at distance "  <<d.second<<endl;
        }



    }

};

int main()
{
    Graph<int >g;
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.printList();
    g.Dijikstra(0);

}
