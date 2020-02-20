#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main()
{
    int arr[]={6,1,-2,1,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>prefArr;
    int sum=0;

    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        prefArr.push_back(sum);

    }

    unordered_set<int> s;
     for(int i:prefArr)
    {
        if(i==0 || s.find(i)!=s.end())
        {
            cout<<"yes";
            break;
        }
        s.insert(i);
    }


}
