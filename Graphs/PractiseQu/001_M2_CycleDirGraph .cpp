#include<bits/stdc++.h>
using namespace std;
/*
Example:
Input:
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2
Output:
1
0
1
*/

bool back_edge(int u,int v,vector<int> adj[],int vert)
{
    bool vis[vert]={false};
    stack<int> s;
    s.push(v);
    vis[v]=true;
    while(!s.empty())
    {
        int i=s.top();
        s.pop();
        for(int x:adj[i])
        {
            if(x==u)
            {
                return true;
            }
            else if(!vis[x])
            {
                vis[x]=true;
                s.push(x);
            }
        }
    }
    return false;
}
bool check(int src,vector<int> adj[], bool vis[],int vert)
{
    queue<int > q;
    q.push(src);
    vis[src]=true;
    
     while(!q.empty())
    {
        int a=q.front();
       // cout<<a<<" ";
        q.pop();
        
        for(int x:adj[a])
        {
            
            if(vis[x]==true && back_edge(a,x,adj,vert)==true)
            {
                return true;
                ///brea
            }
            else if(!vis[x])
            {
                vis[x]=true;
                q.push(x);
                //arr[x]=a;
            }
        
           
        }
    }
    return false;
}

/* IsCycic code
 bool vis[V]={false};
   // int arr[V];
    
    for(int i=0;i<V;i++)
    {
        bool flag;
        if(!vis[i])
        {
            flag= check(i,adj,vis,V);
        }
        if(flag==true)
        {
            return true;
        }
    }
    return false;
*/

bool isCyclic(int v, vector<int> adj[])
{
    // Your code here
   
   bool vis[V]={false};
   // int arr[V];
    
    for(int i=0;i<V;i++)
    {
        bool flag;
        if(!vis[i])
        {
            flag= check(i,adj,vis,V);
        }
        if(flag==true)
        {
            return true;
        }
    }
    return false;
   
    
    
    
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
