#include<iostream>
#define print_a(ar,n) for(int ii=0;ii<n;++ii) cout<<ar[ii]<<" "
using namespace std;

void devide(int arr[],int n,int a,int b)
{
    int l=0;
    int h=n-1;
    
    int i=0;
    while(i<=h)
    {
        if(arr[i]<a)
        {
            swap(arr[l],arr[i]);
            i++;
            l++;
        }
        else if(arr[i  ]>=a && arr[i] <=b)
        {
            i++;
        }
        else
        {
            swap(arr[i],arr[h]);
            h--;
        }
        
    }
}
int main()
{
    int arr[] = {76, 8 ,75 ,22 ,59 ,96 ,30 ,38 ,36};
    int n=sizeof(arr)/sizeof(arr[0]);
    devide(arr,n,44,62);
    print_a(arr,n);

}