#include<iostream>
/*
coins[]={1,2,3}
4
1 1 1 1
*/

using namespace std;
int recursicve(int arr[],int n,int sum)
{
    if(sum==0) return 1;
    if(n==0) return 0;

    int res=recursicve(arr,n-1,sum);

    if(sum>=arr[n-1])
    {
            res+=recursicve(arr,n-1,sum-arr[n-1]);
    }
   

}

int main()
{
        int arr[]={1,2,3};
        int n=sizeof(arr)/sizeof(arr[0]);
        int sum=4;
        cout<<recursicve(arr,n,sum);

}