#include<bits/stdc++.h>
using namespace std;
int* parent;
int* _rank;
int find(int x)
{
    if(parent[x]==x)
        return x;
    return find(parent[x]);
}

void Union(int x,int y)
{
    int x_rep=find(x);

    int y_rep=find(y);

    if(x_rep==y_rep) //Both are in same set
        return;

    if(_rank[x_rep]<_rank[y_rep])
    {


        parent[x_rep]=y_rep;
    }

    else if(_rank[y_rep]<_rank[x_rep])
    {

        parent[y_rep]=x_rep;
    }
    else if(_rank[x_rep] == _rank[y_rep])
    {

        parent[y_rep]=x_rep;
        _rank[x_rep]++;

    }

}
int main()
{
    int n=5;
    parent=new int[n];
    _rank=new int[n];

    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        _rank[i]=0;
    }
    cout<<"Before union"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<parent[i]<<" "<<_rank[i]<<" "<<endl;

    }
    Union(3,4);
    Union(2,3);
    Union(1,2);
    Union(0,1);

    for(int i=0;i<n;i++)
    {
        cout<<parent[i]<<" "<<_rank[i]<<" "<<endl;

    }
}
