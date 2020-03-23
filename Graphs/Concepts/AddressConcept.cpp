
#include<iostream>
using namespace std;
void fun(int *a)
{
    cout<<a<<endl;
    cout<<*a<<endl;
    *a=6;
}
void fun2(int &a)
{
    cout<<a<<endl;
    a=7;
}
int main()
{
    int arr[]={1,2,3};
    int a=5;
    //int b=&a;
    fun(&a);
    fun2(a);
    cout<<a;

}
