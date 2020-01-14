#include<bits/stdc++.h>
using namespace std;
int dfs(int src,unordered_map<int,list<int>> g)
{
    map<int,bool>visited;
    int num=1;//since source node is visited so, one visit is done.
    stack<int>s;
    s.push(src);
    visited[src]=true;
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        for(int neig:g[node])
        {
            if(!visited[neig])
            {
                visited[neig]=true;
                s.push(neig);
                num++;
            }

        }

    }
    return num;
}

unordered_map<int,list<int>> transpose(unordered_map<int,list<int>> g)
{
        unordered_map<int,list<int>> trans;
        for(auto parent: g)
        {
            int p=parent.first;
            for(int child:g[p])
            {
                trans[child].push_back(p);
            }

        }
        return trans;


}

void print(unordered_map<int,list<int>> g)


{
    for(auto parent: g)
        {
            int p=parent.first;
            cout<<p<<"-> ";
            for(int child:g[p])
            {
                cout<<child<<" ";
            }
            cout<<endl;

        }

}

void SCC(unordered_map<int,list<int>> g,int src,int v)
{
    int c1,c2;
    c1=dfs(src,g);
    //cout<<c1;
    if(c1==v)
    {
        unordered_map<int,list<int>> trans=transpose(g);
        c2=dfs(src,trans);
        //cout<<c2;
        if(c2==v)
        {
            cout<<"It is SCC\n";
        }
        else
        {
        cout<<"Not";
        }
    }
    else
    {
        cout<<"Not";
    }


}


int main()
{
    unordered_map<int,list<int>> g;
    g[1].push_back(2);
    g[4].push_back(1);
    g[2].push_back(3);
    g[3].push_back(4);
    SCC(g,1,4);
}
