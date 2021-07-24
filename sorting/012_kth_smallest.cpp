#include<iostream>
#include<vector>
#define v vector<int>
#define print_v(v) for(auto x:v) cout<<x<<" " 
#define end cout<<endl
using namespace std;

int lomuto(v &v1, int l ,int r)
{
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(v1[j]<v1[r-1] && j<(r-2))
        {
            i++;
            swap(v1[j],v1[i]);
        }
    }
    //v1.insert(v1.begin()+i+1,v1[r-1]);
    swap(v1[i+1],v1[r-1]);
    return i+1;
}
int kth(v &v1,int k)
{
    int l=0;
    int r=v1.size();
    
    k=k-1;

    while(l<r)
    {
        int p =lomuto(v1,l,r);
        
        if(p==k) return v1[k];
        
        if(p>k)
        {
            r=p;
        }
        else if(p<k) l=p+1;
    }
    return -1;
}
int main()
{
    v v1= {3,2,5,6,4};

    //lomuto(v1,0,v1.size());

    cout<<kth(v1,1)<<endl;
    print_v(v1);
   
    
}