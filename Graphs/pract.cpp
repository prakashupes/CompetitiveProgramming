
//Not generic

#include<bits/stdc++.h>
using namespace std;


void bfs(unordered_map<int,list<int>> adjList)
{
    map<int,int> inorder;
        queue<int>q;

        //Initialize all inoreder 0
        for(auto x:adjList)
        {
            int node=x.first;

                inorder[node]=0;
                //visited[node]=false;

        }

        //Add inorder for each nodes

        for(auto x:adjList)
        {
            int node=x.first;
            for(auto n:adjList[node])
            {
                inorder[n]++;
            }
        }

        //insert nodes into queue with inorder of 0

        for(auto x:adjList)
        {
            int node=x.first;
            if(inorder[node]==0)
            {
                q.push(node);
            }

        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            //Reduce degree of neighbour of poped node

            for(auto x:adjList[node])
            {
                inorder[x]--;
                if(inorder[x]==0)
                {
                    q.push(x);
                }

            }

        }

    }





int main()
{
    unordered_map<int,list<int>> adjList;
    adjList[1].push_back(4);
    adjList[1].push_back(2);
    adjList[2].push_back(3);
    adjList[3].push_back(5);
    adjList[4].push_back(3);
    adjList[4].push_back(5);
    adjList[5].push_back(6);
    adjList[7].push_back(4);
    bfs(adjList);



}
