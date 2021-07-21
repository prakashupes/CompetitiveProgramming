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

//using hoare

int hoare(int arr[],int l,int h)
{
    int p=l;
    int i=l-1;
    int j=h+1;
    
    while(true)
    {
        do{i++;}
        while (arr[i]<arr[p]);
        do{j--;}
        while(arr[j]>arr[p]);

        if(i>=j) return j;

        swap(arr[i],arr[j]);
 
    }
}

void quick_2(int arr[],int l,int h)
{
    if(l<h)
    {
        int p=hoare(arr,l,h);
        quick_2(arr,l,p);
        quick_2(arr,p+1,h);

    }
}

int main()
{
    //int arr[]={1,1};
    int arr[]={2,5,3,9,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    //quick_sort(arr,0,n);
    quick_2(arr,0,n-1);
   // cout<<hoare(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}