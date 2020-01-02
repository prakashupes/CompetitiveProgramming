#include<iostream>
#include<vector>

using namespace std;

int main()
{
    cout<<"Enter num of vertices\n";
    int N,u,v,E;
    cin>>N;
    cout<<"Enter edges\n";
    cin>>E;
    vector<int> arr[N];
    cout<<"Enter pair of edges\n";
    for(int i=0;i<E;i++)
    {
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for(int i=0;i<N;i++)
    {
        cout<<i<<"-> ";
        for(int x:arr[i])
        {
            cout<<x<<" ";

        }
        cout<<endl;

    }


}
