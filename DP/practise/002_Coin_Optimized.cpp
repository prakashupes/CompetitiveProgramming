#include <iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    int a=n/100;
    int b=a+n%100/20;
    int c=b+n%20/10;
    int d=c+n%10/5;
    int e=d+n%5;
    cout<<e;
 
}