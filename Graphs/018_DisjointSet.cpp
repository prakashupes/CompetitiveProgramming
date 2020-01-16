#include<bits/stdc++.h>
using namespace  std;
int* parent ;
void initialize(int n)
{
    parent=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
}

int find(int x)
{
    if(parent[x]==x)
        return x;
    else return(find(parent[x]));

}

void Union(int x,int y)
{
    int x_rep=find(x);
    int y_rep=find(y);
    if(x_rep==y_rep)
        return;
    parent[y_rep]=x_rep;

}
int main()
{
    //0,1,2,3,4
    //Union(0,1);
    cout<<"Here each set represent by one representative element\n";
    initialize(5);

    Union(0,1);
    Union(1,2);
    Union(3,4);
    Union(0,4);

    for(int i=0;i<5;i++)
    {
        cout<<parent[i]<<" ";
    }

    cout<<"\nParent[3] is also 0 means all from same set\n";

}
