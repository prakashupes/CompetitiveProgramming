#include<bits/stdc++.h>
using namespace std;
int area(vector<int> v)
{
    stack<int>s;
    int res=0;
    for(int i=0;i<v.size();i++)
    {
        while(!s.empty() && v[s.top()]>=v[i])
        {
            //now here v[i]:next smaller
            //arr[top]:current 
            //arr[prev top()]:prev smaller
            int tp=s.top();
            s.pop();
            int ar=v[tp]* (s.empty() ? i:(i-s.top()-1));
            res=max(res,ar);
        }
        //cout<<res;
        s.push(i);
    }

    //for all the elemets which does not have next smaller will not be get removed
    int n=v.size();
    while(!s.empty())
    {
        int ar=v[s.top()]*  (s.empty() ? n:(n-s.top()-1));
        s.pop();
        res=max(ar,res);
    }
    return res;
}
int main()
{
    vector<int> v={6,2,5,4,5,1,6};
    cout<<area(v);
}