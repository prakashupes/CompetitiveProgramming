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

bool dfs(int v, vector<int> adj[],bool vis[], bool c[], int src, bool * flag)
{
    vis[src]=true;
    
    for(auto x: adj[src])
    {
        if(vis[x]==true && c[x]==false)
        {
            *flag=true;
        }
        else if(!vis[x])
        {
            //vis[x]=true;
            dfs(v,adj,vis,c,x,flag);
        }
        
        
    }
    c[src]=true;
    return flag;
}
bool isCyclic(int v, vector<int> adj[])
{
    // Your code here
   
    bool vis[v]={false};
    bool c[v]={false}; //completed dfs for perticular vertex
    bool flag=false;
    bool flag2=false;
    for(int i=0 ;i<v ;i++)
    {
        
        if(!vis[i])
        {
            dfs(v,adj,vis,c,i,&flag);
            if(flag)
            {
                return true;
            }
            
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
