#include<bits/stdc++.h>
using namespace std;
#define v vector<int>
void intersec(vector<int>& v1, vector<int>& v2)
{
    int n=v1.size();
    int m=v2.size();

    int i=0,j=0;

    while(i<n && j<m)
    {
        if(i>0 && v1[i]==v1[i-1]) //avoid repetetion
        {
            i++;
            continue;
        }

        if(v1[i]==v2[j])
        {
            cout<<v1[i]<<" ";
            i++;j++;
        }
        else if(v1[i]<v2[j])i++;
        else j++;
    }
}


int main()
{
    v v1={-1,2,2,3,4,5,5,6};
    v v2= {-1,2,3,3,4,5};

    intersec(v1,v2);
    cout<<endl;
}