#include<iostream>
using namespace std;
bool isSorted(int arr[],int n)
{
    if(n==0 || n==1)
        return true;
    if(arr[n-1]>=arr[n-2] && isSorted(arr,n-1))
        return true;
    else
        return false;

}
int main()
{
    int arr[]={1,2,3,4,3,5};
    if(isSorted(arr,5))
        cout<<"Sorted";
    else
        cout<<"Not";
}
