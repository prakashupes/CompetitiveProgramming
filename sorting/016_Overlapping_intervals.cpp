#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;


bool sort_pair(pp a, pp b)
{
    return a.first < b.first;
}
//needs to fix
vector<pp> overlap_merge(vector<pp> v)
{
    vector<pp> res;
    sort(v.begin(),v.end(),sort_pair);
  
    for(int i=0;i<v.size();i++)
    {
        if(v[i].second>v[i+1].first)
        {
            res.push_back({v[i].first,max(v[i].second,v[i+1].second)});
            i++;
        }
        else
        {
            res.push_back(v[i]);
            
        }
        
    }
    return res;

}
int main()
{
    vector<pair<int,int>> v = {{7,9},{6,10},{4,5},{1,3},{2,4} };
    
    vector<pp> res=overlap_merge(v);
    //sort(v.begin(),v.end(),sort_pair);
    for(auto x: res)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}