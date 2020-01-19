#include<bits/stdc++.h>
//Have to work on it
using namespace std;
class Friend
{
    map<int,list<int>> adjList;
    public:

    void makeFriend(int f1, int f2)
    {
        adjList[f1].push_back(f2);
        adjList[f2].push_back(f1);

        for(int i:adjList[f1])
        {
            if(i==f1 || i==f2)
            {


            }
            else
            {
                adjList[f2].push_back(i);
                adjList[i].push_back(f2);

            }

        }


    }
    void isFriend(int f1,int f2)
    {
        for(auto x:adjList)
        {
            cout<<x.first<<"->";
            for(int y:adjList[x.first])
            {
                cout<<y<<" ";
            }
            cout<<endl;
        }

    }
};
int main()
{
    Friend f;
    f.makeFriend(0,1);
    f.makeFriend(0,3);
    f.makeFriend(2,4);
    f.makeFriend(2,0);
    f.isFriend(2,0);
}
