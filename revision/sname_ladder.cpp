// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int helper(list<int> *l, int src,int dest)
    {
     
        unordered_map<int,bool> vis;
        queue<int> q;
        q.push(src);
        
        int cur_node=src;
        vis[src]=true;
        unordered_map<int,int> dist;
        dist[src]=0;
        
        while(!q.empty())
        {
            int parent=q.front();
            q.pop();
            
            for(auto node:l[parent])
            {
                if(!vis[node])
                {
                    dist[node]=dist[parent]+1;
                    vis[node]=true;
                    q.push(node);
                }
            }
        }
        for(auto x: dist)
        {
            //cout<<x.first<<" "<<x.second<<endl;
        }
        return dist[dest];
    }
    int minThrow(int N, int arr[]){
        // code here
        list<int> * adjlist = new list<int>[50];
        int jump[50] = {0};
        
        
        for(int i=0;i<2*N-1;i+=2)
        {
            jump[arr[i]]=arr[i+1]-arr[i];
        }
        for(int i=0;i<=30;i++)
        {
           // cout<<jump[i]<<" ";
        }
        
        for(int i=1;i<=30;i++)
        {
            for(int j=1;j<=6;j++)
            {
                int v=j+i+jump[i+j];
                adjlist[i].push_back(v);
            }
        }

/*
        for(int i=0;i<=30;i++)
        {
            cout<<i<<"->";
            for(auto x:adjlist[i])
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
        */
       return helper(adjlist,1,30);
       //return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

/*
1
8
3 22 5 8 11 26 20 29 17 4 19 7 27 1 21 9

*/