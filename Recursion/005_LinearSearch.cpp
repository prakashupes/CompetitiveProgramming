#include<iostream>
using namespace std;
int linear(int arr[],int key,int n)
{
    if(n==0)
        return -1;

    if(arr[n]==key)
        return n;
    return linear(arr,key,n-1);
}
int main()
{
    int arr[]={1,2,3,7,5};
    int siz=sizeof(arr)/sizeof(arr[0]);
   // cout<<siz<<endl;
    cout<<linear(arr,7,siz);
}
