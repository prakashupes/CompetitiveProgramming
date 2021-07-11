#include<bits/stdc++.h>
using namespace std;
#define v vector<int>

void union_m1(v v1,v v2)
{
    int n=v1.size();
    int m=v2.size();

    int i=0,j=0;

    while(i<n && j<m)
    {
        if(i>0 && v1[i]== v1[i-1])
        {
            i++;
            continue;

        }
        if(v1[i]==v2[j])
        {
            cout<<v1[i]<<" ";
            i++;
            j++;
        }
        else
        {
            cout<<v1[i]<<" "<<v2[j];
            i++;
            j++;
        }
    }

    while(i<n) {cout<<v1[i++]<<" ";
    if(i>0 && v1[i]== v1[i-1])
        {
            i++;
            continue;

        }
    }
    while(j<m){
      if(j>0 && v2[j]== v2[j-1])
        {
            j++;
            continue;

        }  
        cout<<v2[j++]<<" ";
    } 
}


//using set
void union_m2(v v1,v v2)
{
    set<int> s;
    for(auto x:v1) s.insert(x);
    for(auto x:v2) s.insert(x);
    for(auto x:s) cout<<x<<" ";
}


int main()
{
    v v1 ={1,1,2,3,4};
    v v2={1,2,3,4,5,5,6};
    union_m2(v1,v2);
    cout<<endl;
    union_m1(v1,v2);
}