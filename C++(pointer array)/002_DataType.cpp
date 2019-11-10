#include<iostream>
using namespace std;
int main()
{
    int a=2147483648; /**  int a, can not store more then this link. 2147483648 will give -ve */
    // Long int is same as int

    cout <<" size of int "<<sizeof(a)<<"bytes"<<endl;
    cout<<"Will give -ve num bcz of range "<<a<<endl;
    long long int b=2147483648;
    cout<<b;

}
