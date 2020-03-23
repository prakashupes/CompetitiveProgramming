//Refrance
//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/?track=md-graph&batchId=144
/*Example:
Input:
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
5 4
0 1 2 3 3 4 4 2

Output:
1
0
1
*/
// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
bool dfs(vector<int> adj[], int V,int src, bool vis[],int parent[])
{
    
    vis[src]=true;
    queue<int> s;
    s.push(src);
    while(!s.empty())
    {
        int top=s.front();
        s.pop();
        for(int i:adj[top])
        {
            if(i==top)
            {
                return true;
            }
            if(vis[i]==true && parent[top]!=i)
            {
                return true;
                
            }
            if(!vis[i])
            {
                vis[i]=true;
                s.push(i);
                parent[i]=top;
            }
             
        }
        
    }
    
    return false;
    
}

bool isCyclic(vector<int> adj[], int V) //Array of vectors
{
   // Your code here
  // int src=0;
   bool vis[V]={false};
   bool flag=false;
   int parent[V]={-1};
   
   for(int i=0;i<V;i++)
   {
       if(!vis[i])
       {
           flag=dfs(adj,V,i,vis,parent);
           if(flag)
           {
             return true;;
           }
            
       }
   }
   return false;
   
   // for (auto neighbor : adj[4]) { cout << neighbor << " "; }
    // cout << endl;

    
   
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
