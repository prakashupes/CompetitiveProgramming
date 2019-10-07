#include<iostream>
using namespace std;
void basic()
{
    int a=5;
    int *p;
    p=&a;
    int **q;
    q=&p;

    cout<<*p<<endl;
    cout<<p<<endl;
    cout<<**q;
}
void arrayPointer()
{
    int arr[3]={5,2,3};

      //arr denotes the address of first element
    cout<<&arr<<endl<<arr<<endl<<&arr[0]<<endl; //all are same

    //We also can use a pointer to the arr;
    //Since arr returns an address so it can store in pointer

    int *p;
    p=arr;
    cout<<p<<endl;

    cout<<*p<<endl; //Since p points to the address of arr which is also address of arr[0], so *p will value at that address

    //we can increment

    for(int i=0;i<3;i++)
    {
        cout<<*p<<" ";
        p++;
    }



}

int main()
{
   arrayPointer();


}
