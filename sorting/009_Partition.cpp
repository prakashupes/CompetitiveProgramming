#include<iostream>
#include<algorithm>
using namespace std;
void partition(int arr[],int n,int l)
{
    int p=n-1;
    int i=l-1;

    for(int j=l;j<n;j++)
    {
        if(arr[j]<=arr[p] && i<(n-2))
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[n-1]);

}
int main()
{
    //int arr[]={70,60,80,40,30};
   int arr[]={30,40};
    int n = sizeof(arr)/sizeof(arr[0]);

    partition(arr,n,0);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}