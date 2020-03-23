#include<iostream>
#include<algorithm>
using namespace std;

class Edge
{
    public:
    int src,des,wt;
    Edge(int s,int d,int w)
     {
        this->src=s;
        this->des=d;
        this->wt=w;
     }
     Edge()
     {


     }


};
//Global arrays

int* parent;
int *Rank;
Edge* MST;
bool sortByWt(Edge e1,Edge e2)
{
    return e1.wt<e2.wt;
}


int find_(int x)
{
    if(x==parent[x])
        return x;
    parent[x]=find_(parent[x]);
    return parent[x];

}

void Union(int x,int y)
{
    //Here x and y are Representative

    if(Rank[x]<Rank[y])
    {
        parent[y]=x;
    }
    else if(Rank[y]<Rank[x])
    {
        parent[x]=y;
    }
    else if(Rank[x]==Rank[y])
    {
        parent[x]=y;
    }
}
int Krushkal(Edge graph[],int v)
{
    sort(graph,graph+v,sortByWt); //Sort by wt
    int res=0;//Total wt
    for(int i=0,s=0;s<v-1;i++) //S is size of MST
    {
        int x=find_(graph[i].src);
        int y=find_(graph[i].des);
        if(x!=y) //Cycle not exist
        {
            res=res+graph[i].wt;

            Union(x,y);
            MST[s]=graph[i];
            s++;

        }

    }
    return res;

}

int main()
{
    int v=5,e=7;
    Edge graph[e];

    //All properties of edge 1
    graph[0].src=0;
    graph[0].des=1;
    graph[0].wt=10;
    //All properties of edge 2
    graph[1].src=0;
    graph[1].des=2;
    graph[1].wt=8;
    //All properties of edge 1
    graph[2].src=1;
    graph[2].des=3;
    graph[2].wt=3;
    //All properties of edge 1
    graph[3].src=1;
    graph[3].des=2;
    graph[3].wt=5;
    //All properties of edge 1
    graph[4].src=2;
    graph[4].des=3;
    graph[4].wt=4;

    //All properties of edge 1
    graph[5].src=2;
    graph[5].des=4;
    graph[5].wt=12;

    //All properties of edge 7

    //graph[6]=Edge(3,4,15);

    graph[6].src=3;
    graph[6].des=4;
    graph[6].wt=15;

    //Parent array will have size V

    parent=new int[v];
    Rank=new int[v];
    MST=new Edge[v-1];
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
        Rank[i]=0;
    }
    int res=Krushkal(graph,v);
    cout<<res<<endl;
    for(int i=0;i<v-1;i++)
    {
        cout<<MST[i].src<<" "<<MST[i].des<<" "<<MST[i].wt<<endl;
    }




}
