#include<iostream>
using namespace std;
int main()
{
    int *arr= new int[10];
    arr[0]=10;
    arr[1]=2;
    cout<<arr[0]<<" "<<*(arr+1)<<endl;
    arr[11]=4;
    cout<<arr[11]<<" size arr "<<sizeof(arr)<<endl;

    int arr2[5];
    arr2[4]=5;
    cout<<arr2[4]<<" "<<sizeof(arr2)<<endl;

}
