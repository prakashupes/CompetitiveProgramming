#include<iostream>
#include<algorithm>
using namespace std;
void partition(int arr[],int n,int l)  //lomuto partetion
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


int hoare(int arr[],int h,int l)
{
    int p=arr[0];
 
    int i=l-1;
    int j=h+1;

    while(1)
    {

        do{
           
            i++;
            
        }while(arr[i]<p);

        do{
            j--;
        }while(arr[j]>p);

        if(i>=j) return j;

       
        swap(arr[i],arr[j]);


    }
}
//pivot is not last element

int main()
{
    int arr[]={3,2,6,8,1,1};
   //int arr[]={30,40};
    int n = sizeof(arr)/sizeof(arr[0]);

partition(arr,n,0);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
   /* 
    cout<<hoare(arr,n,0)<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    */

}