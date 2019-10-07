#include<iostream>
using namespace std;
//we always need to pass array and size both

void pass(int* arr,int size) // pass(int arr[],int size)
{
    cout<<"In fun "<<arr<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<*arr<<endl; //cout<<arr[i]<<endl; is also same
        arr++;
    }
    //if we modify anything then it also reflect in main()

    //If here i will do some operation then it will not reflect becz, arr pointer is incremented


}
void pass2(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        arr[i]=2*arr[i]; //*arr=2*(*arr);
    }
}
int main()
{
    int arr[]={1,2,3};
    int size=(sizeof(arr)/sizeof(arr[0]));
    cout<<size<<endl;
    cout<<"In main "<<arr<<endl;
    pass(arr,size);
    pass2(arr,size);
    for(int i=0;i<size;i++)
    {

        cout<<" " <<arr[i];
    }
}
