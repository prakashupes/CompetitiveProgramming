 #include<bits/stdc++.h>
 using namespace std;
 class Graph
 {
     public:
     int v;
     //vector<vector<int>> adlist;

     list<int> *l;
     Graph(int n){
         this->v=n;
         l=new list<int>[v];
     }
    
    void insert(int u,int v,bool bide=true)
    {
        if(bide)
        {
                l[u].push_back(v);
                l[v].push_back(u);
        }
    }
    void  print_list(Graph g)
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";
            for(auto x:g.l[i])
            {
                cout<<x<<", ";
            }
        }
    }

    void bfs(Graph &g,int src)
    {
        map<int ,bool> vis;
        vis[src]=1;
        stack<int> s;
        s.push(src);
        while(!s.empty())
        {
            int curr=s.top();
            s.pop();
            cout<<curr<<" ";

            for(auto x:g.l[curr])
            {
                    if(!vis[x])

                    {
                        s.push(x);;
                        vis[x]=true;
                    }
            }
            
        }
    }

    void dfs(int src)
    {   
        unordered_map<int ,bool> vis;
        queue<int> q;
        q.push(src);
        vis[src]=true;

        while (!q.empty())
        {
            int curr=q.front();
            q.pop();
            cout<<curr<<" ";

            for(auto x:l[curr])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]=true;
                }
                

            }
        }
        
    }



 };

template <class T>
 class Graph_2{
     unordered_map<T,list<T>> adjList;

     public:
     void insert(T u,T v,bool bid=true)
     {
         if(bid)
         {
             adjList[u].push_back(v);
             adjList[v].push_back(u);
         }
     }


 };

 void helper(unordered_map<int,list<int>> adjList,unordered_map<int,bool> &vis,stack<int>& order,int src)
{
    vis[src]=true;

    for(auto x: adjList[src])
    {
        if(!vis[x])
        {
            helper(adjList,vis,order,x);
        }
    }
    order.push(src);
}


 void topological(unordered_map<int,list<int>> adjList)
 {
     unordered_map<int,bool> vis;
     stack<int> order;

     for(auto node: adjList)
     {
         if(!vis[node.first])
         {
             helper(adjList,vis,order,node.first);
         }
     }

     while(!order.empty())
     {
         cout<<order.top()<<" ";
         order.pop();
     }
     
 }
 
 int main()
 {
     Graph g(7);
     g.insert(0,1);
     g.insert(0,3);
     g.insert(1,2);
     g.insert(3,4);
     g.insert(1,3);
     g.insert(2,6);
     g.insert(4,5);
    // g.print_list(g);
    // g.bfs(g,0);
     cout<<endl;
     //g.dfs(0);




//topological
    unordered_map<int,list<int>> adjList;
    adjList[1].push_back(4);
    adjList[1].push_back(2);
    adjList[2].push_back(3);
    adjList[3].push_back(5);
    adjList[4].push_back(3);
    adjList[4].push_back(5);
    adjList[5].push_back(6);
    adjList[7].push_back(4);
    topological(adjList);

 }