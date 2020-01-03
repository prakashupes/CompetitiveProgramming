#include<bits/stdc++.h>
using namespace std;
//SSSP
void shortestPath(int s,vector<int> adjList[],int n)
{
    queue<int> q;
    q.push(s);
    bool visited[n+1]={false};
    int distance[n+1];
    for(int i=0;i<=n;i++)
    {
        distance[i]=-1;
    }

    distance[s]=0;
    visited[s]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int x:adjList[node])
        {
            if(!visited[x])
            {
                distance[x]=distance[node]+6;
                visited[x]=true;
                q.push(x);

            }

        }

    }


    for(int i=0;i<n;i++)
    {

        if(i+1==s)
        {

        }
        else
        {
            cout<<distance[i+1]<<" ";
        }
    }




}
int main() {
	int q;
    cin>>q;

    while(q>0)
    {
        int n,m;
        cin>>n>>m;
        vector<int> adj[n+1];

        int u,v;
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int s;
        cin>>s;
        shortestPath(s,adj,n);
        q--;
    }
}
