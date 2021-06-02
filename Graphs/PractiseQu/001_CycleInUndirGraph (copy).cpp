#include<bits/stdc++.h>
using namespace std;

int solve (int n,vector<int> f, vector<int> t)
{
    if(n==0) return 0;
    if(f.size()==0|| t.size()==0) return n;
    int count=0,ans=0;
    bool v[f.size()]={0};

    set<int> s;
    int prev=0;
    s.insert(f[0]);
    for(int i=0;i<f.size();i++)
    {
        if(s.find(f[i])==s.end() && s.find(t[i])==s.end() )
        {
            count+=s.size();
            int temp=ceil(sqrt(s.size()));
            prev=temp;
            ans+=temp;
            s.clear();
            
            s.insert(f[i]);
            i--;
        }
        else
        {
            v[f[i]]=1;
            v[t[i]]=1;
            s.insert(f[i]);
            s.insert(t[i]);
        }
       
        
    }
    if(!s.empty())
    {
        
        
            
            count+=s.size()+prev;
        int temp=ceil(sqrt(s.size()));
        ans+=temp;
        
        
        
       
        s.clear();
    }
     ans+=(n-count);
    return ans;
}
int main()
{
    vector<int> v ={1,1,2,3,7};
    vector<int> v2={2,3,4,5,8};
    cout<<solve(10,v,v2);
}