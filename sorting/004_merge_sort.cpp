#include<iostream>
using namespace std;
void merge(int arr[],int l,int h,int mid)
{
   int n=mid-l+1;
   int m=h-mid;
   int arr1[n],arr2[m];
   for(int i=0;i<n;i++)
   {
       arr1[i]=arr[l+i];
   }
   for(int j=0;j<m;j++)
       arr2[j]=arr[mid+1+j];
   
    int k=l;
    int i=0,j=0;

   while(i<n && j<m)
   {
       if(arr1[i]<=arr2[j]){
           arr[k++]=arr1[i++];
       }
       else{
           arr[k++]=arr2[j++];
       }
   }

   while(i<n)
   {
           arr[k++]=arr1[i++];
   }
   while(j<m)
   {
       arr[k++]=arr2[j++];
   }
}

void merge_sort(int arr[],int l,int r)
{
    if(l<r) //more then one element
    {
        int mid=l+(r-l)/2;
    
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
    return;
    
}

int main()
{
    int arr[]= {1,9,4,6,3,2,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}