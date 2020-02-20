#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int arr[]={6,1,-2,1,-1};
    //vector<int> v{arr,arr+5};
    //cout<<v[0];
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;

    for(int i=0;i<n;i++)
    {
        sum=arr[i];
        for(int j=i+1;j<n;j++)
        {

            sum+=arr[j];
            if(sum==0)
            {
                cout<<i<<" to "<<j<<endl;
            }
        }
    }


}
