//Let we have an array which contains two types of elements, +-v1 and negative,
// odd and even , binary(0/1), we need to segregate them.
#include<iostream>
using namespace std;
#define print_a(arr,n) for(int ii=0;ii<n;ii++)cout<<arr[ii]<<" " 

void segregate(int arr[],int l,int h)
{
    if(h==1) return ;
    int i=l-1,j=h+1;

    while (true)
    {
        do{i++;}
        while(arr[i]<0);
        do{j--;}
        while(arr[j]>0);

        if(i>j)return;

        swap(arr[i],arr[j]);
    }
    
}

int main()
{
    int arr[]={2,-2,-3,-4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    segregate(arr,0,n);
    print_a(arr,n);

}