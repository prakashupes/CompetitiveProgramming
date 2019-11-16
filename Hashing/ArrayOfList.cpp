#include<iostream>
#include<list>
using namespace std;
int main()
{
    //list <int> arr[25]; //Static

    list<int> *arr2=new list<int>[25]; //Dynamic

    int* arr=new int[3];
    arr[2]=5;
    cout<<arr[2];


}
