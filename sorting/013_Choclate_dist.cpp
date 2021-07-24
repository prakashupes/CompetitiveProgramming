#include<bits/stdc++.h>
#define v vector<int>
#define print_v(v) for(auto x:v) cout<<x<<" " 
#define line cout<<endline
using namespace std;

int solver(v v1,int m)
{
    int ans=1e9+7;
    sort(v1.begin(),v1.end());
    for(int i=0;i<=v1.size()-m;i++)
    {
        int temp=v1[i+m-1]-v1[i];
        
        
        ans= min(ans,temp);

        

    }
    return ans;

}
int main()
{
    v v1={12, 4, 7, 9, 2, 23, 25, 41, 
30, 40, 28, 42, 30, 44, 48, 
43, 50} ;
    int m=7;
    cout<<solver(v1,m)<<endl;

}