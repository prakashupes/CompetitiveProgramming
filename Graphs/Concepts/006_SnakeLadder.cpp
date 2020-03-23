#include<bits/stdc++.h>
//First make a graph for whole board
using namespace std;
void shortestPath(int src,int dest,list<int> adjList[50])
{
    map<int,bool>visited;
    map<int,int> distance;
    visited[src]=true;
    distance[src]=0;

    map<int,int>parentMap;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        for(int neigh:adjList[parent])
        {
            if(!visited[neigh])
            {
                visited[neigh]=true;
                distance[neigh]=distance[parent]+1;
                parentMap[neigh]=parent;
                q.push(neigh);
            }
        }

    }

    cout<<distance[dest]<<endl;

    int temp=dest;
    //Statck for forward path
    stack<int>s;
    while(temp!=src)
    {
        s.push(temp);
        temp=parentMap[temp];



    }
    while (!s.empty())
    {
        cout << s.top()<<" ->";
        s.pop();
    }
}
int main()
{
    int board[50]={0};//It represents the value of board at perticular position
    board[2]=13;//Means if we are at 2, we directly go to the 15(2+13)
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;
    //AdjList
    list<int> adjList[50];
    //Find pair of edges
    for(int u=0;u<=36;u++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int v=u+dice+board[dice+u];
            adjList[u].push_back(v);
        }
    }
    shortestPath(1,36,adjList);


}

