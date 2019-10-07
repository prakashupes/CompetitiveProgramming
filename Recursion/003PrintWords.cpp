#include<iostream>
using namespace std;
char arr[][6]={"zero","one","two","three","four"};

void print(int n)
{
    if(n==0)
        return;
    print(n/10);
    cout<<arr[n%10]<<" ";

}
int main()
{
    int n=32142;
    print(n);


}
