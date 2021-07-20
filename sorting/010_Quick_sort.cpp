#include<iostream>
using namespace std;
int lomuto(int arr[],int l,int h)
{
    int p=h-1;
    int i=l-1;

    for(int j=l;j<h;j++)
    {
        
        if(arr[j]<=arr[p] && i<(h-2))
        {
            
            i++;
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[i+1],arr[p]);
    return i+1;

}
void quick_sort(int arr[],int l,int h)
{
    if(l<h)
    {   
        int p=lomuto(arr,l,h);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,h);

    }
}

int main()
{
    int arr[]={3,2,6,-8,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,n);

   // cout<<lomuto(arr,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}