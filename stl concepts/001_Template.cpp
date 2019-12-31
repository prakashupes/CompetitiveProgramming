#include<iostream>
using namespace std;
template <typename T>
void printArray(T arr,int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={1,2,3,4,5};
    cout<<"Printing Int arr\n";
    printArray(arr,5);
    cout<<"\n\nPrinting Char array with same function\n";

    char arr2[]={'a','b','c'};
    printArray(arr2,3);

}
